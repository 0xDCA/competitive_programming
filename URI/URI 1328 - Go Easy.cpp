#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <utility>
#include <map>
#include <climits>

using namespace std;

struct Station {
   int zone;
   vector<pair<int, int> > transports;

   Station() : zone(-1), 
      transports(vector<pair<int, int> >()) {  }
};

struct Transport {
   char type;
   vector<int> itineraries;
};

struct Edge {
   pair<int, int> to;
   int cost;

   Edge(pair<int, int> t, int c) : to(t), cost(c) { }
};

struct Node {
   int distance, station, transport;
   vector<Edge> edges;
   bool edgesCalculated;
   pair<int, int> previous;

   Node() : station(-1), transport(-1), distance(INT_MAX),
      edges(vector<Edge>()), edgesCalculated(false),
      previous(pair<int, int>(-1, -1)) { }
   Node(int st, int tr) : station(st), transport(tr), 
      distance(INT_MAX), edges(vector<Edge>()), edgesCalculated(false),
      previous(pair<int, int>(-1, -1)) { }
};

vector<Station> stations;
vector<Transport> transports;
vector<vector<Node> > nodes;

struct NodeReference {
   pair<int, int> pos;
   int distance;

   NodeReference(pair<int, int> p) : pos(p) 
   { 
      distance = nodes[pos.first][pos.second].distance;
   }

   bool operator<(const NodeReference other) const {
      return distance > other.distance;
   }
};

void initNodes(int from, int to) {
   nodes = vector<vector<Node> >(stations.size() + 2);

   vector<Node> internal;
   internal.push_back(Node(from, -1));
   internal[0].distance = 2;
   nodes[stations.size()] = internal;

   internal[0] = Node(to, -1);
   nodes[stations.size() + 1] = internal;

   for(int i = 0; i < stations.size(); ++i) {
      const Station& s = stations[i];

      for(int j = 0; j < s.transports.size(); ++j) {
         Node n(i, j);
         
         if (i == from)
            nodes[stations.size()][0].edges.push_back(Edge(pair<int, int>(i, j), 
                     transports[s.transports[j].first].type == 'B' ? 1 : 0));
         if (i == to)
            n.edges.push_back(Edge(pair<int, int>(stations.size() + 1, 0), 0));

         if (j >= nodes[i].size())
            nodes[i].resize(j + 1);
         nodes[i][j] = n;
      }
   }   
}

int getMinPrice(int from, int to) {
   initNodes(from, to);

   vector<NodeReference> heap;
   vector<vector<bool> > visited(nodes.size());
   for(int i = 0; i < nodes.size(); ++i) {
      visited[i] = vector<bool>(nodes[i].size(), false);
   }

   heap.push_back(NodeReference(pair<int, int>(stations.size(), 0)));

   while(!heap.empty()) {
      pair<int, int> current = heap.front().pos;
      Node& minNode = nodes[current.first][current.second];
      pop_heap(heap.begin(), heap.end());
      heap.pop_back();

      if (visited[current.first][current.second])
         continue;

      if (current.first == stations.size() + 1)
         break;

      if (minNode.distance == INT_MAX)
         break;

      if (!minNode.edgesCalculated && current.first < stations.size()) {
         static const int Offsets[] = { 1, -1 };

         const Station& st = stations[minNode.station];
         const pair<int, int>& p = st.transports[minNode.transport];
         const Transport& t = transports[p.first];
         int index = p.second;

         // Nodes in station

         int cost;
         for(int i = 0; i < st.transports.size(); ++i) {
            if (st.transports[i] == p)
               continue;
            cost = 0;
            int nextIndex = st.transports[i].first;
            const Transport& nextT = transports[nextIndex];
            if (nextT.type == 'B')
               cost = nextIndex == p.first ? 0 : 1;

            minNode.edges.push_back(Edge(pair<int, int>(minNode.station, i), cost));
         }

         // Next stations using this transport
         for(int j = 0; j < 2; ++j) {
            if(index + Offsets[j] < 0 ||
                 index + Offsets[j] >= t.itineraries.size())
               continue;

            int nextStationIndex = t.itineraries[index + Offsets[j]];
            const Station& nextStation = stations[nextStationIndex];
   
            for(int k = 0; k < nextStation.transports.size(); ++k) {
               int nextTransportIndex = nextStation.transports[k].first;
               if (nextTransportIndex != p.first)
                  continue;
               const Transport& nextTransport = transports[nextTransportIndex];

               int cost = 0;
               if(nextTransport.type == 'T')
                  cost = st.zone != nextStation.zone ? 4 : 0;

               minNode.edges.push_back(Edge(pair<int, int>(nextStationIndex, 
                     k), cost));
            }
         }

         minNode.edgesCalculated = true;
      }

      for(int i = 0; i < minNode.edges.size(); ++i) {
         int alt = minNode.distance + minNode.edges[i].cost;
         Node& neighbour = nodes[minNode.edges[i].to.first][minNode.edges[i].to.second];

         if (!visited[minNode.edges[i].to.first][minNode.edges[i].to.second] &&
               alt < neighbour.distance) {
            neighbour.distance = alt;
            neighbour.previous = current;
            heap.push_back(NodeReference(minNode.edges[i].to));
            push_heap(heap.begin(), heap.end());
         }
      }

      visited[current.first][current.second] = true;
   }

   return nodes[stations.size() + 1][0].distance;
}

Transport readTransport() {
   int k;
   cin >> k;
   vector<int> itineraries(k);

   for(int i = 0; i < k; ++i) {
      cin >> itineraries[i];
      --itineraries[i];
   }

   Transport result;
   result.itineraries = itineraries;

   return result;
}

int main() {
   int zoneCount, stationCount;

   while(cin >> zoneCount >> stationCount &&
         zoneCount > 0 && stationCount > 0) {
      stations = vector<Station>(stationCount);
      
      for(int i = 0; i < zoneCount; ++i) {
         int k;
         cin >> k;

         for(int j = 0; j < k; ++j) {
            int value;
            cin >> value;
            stations[value - 1].zone = i;
         }
      }

      int trainCount, busCount;
      cin >> trainCount >> busCount;

      transports = vector<Transport>(trainCount + busCount);
      for(int i = 0; i < transports.size(); ++i) {
         transports[i] = readTransport();
         transports[i].type = i < trainCount ? 'T' : 'B';

         for(int j = 0; j < transports[i].itineraries.size(); ++j) {
            stations[transports[i].itineraries[j]]
               .transports.push_back(pair<int, int>(i, j));
         }
      }

      int from, to;
      cin >> from >> to;
      
      int result = getMinPrice(from - 1, to - 1);

      cout << result << '\n';
   }
}
