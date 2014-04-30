#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

int main() {
   int n, m;

   while(cin >> n >> m) {
      if (n == 0 && m == 0)
         break;

      map<string, vector<int> > serversForApp;
      vector<vector<bool> > connected(n, vector<bool>(m, false));
      int connectionCount = 0;

      int apps;
      string app;
      for(int i = 0; i < n; ++i) {
         cin >> apps;

         for(int j = 0; j < apps; ++j) {
            cin >> app;

            serversForApp[app].push_back(i);
         }
      }

      for(int i = 0; i < m; ++i) {
         cin >> apps;

         for(int j = 0; j < apps; ++j) {
            cin >> app;

            const vector<int>& servers = serversForApp[app];
            for(int k = 0; k < servers.size(); ++k) {
               if(!connected[servers[k]][i]) {
                  connected[servers[k]][i] = true;
                  ++connectionCount;
               }
            }
         }
      }

      cout << connectionCount << '\n';

   }
}
