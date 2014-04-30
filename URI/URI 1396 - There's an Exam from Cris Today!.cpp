#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
   int n, maxSwaps, c = 1;

   while(cin >> n >> maxSwaps && n > 0) {
      vector<string> names(n);
      map<string, int> order;

      for(int i = 0; i < n; ++i) {
         cin >> names[i];
         order[names[i]] = i;
      }

      int target = 0;

      while(!order.empty() && maxSwaps > 0) {
         for(map<string, int>::iterator it = order.begin();
               it != order.end() && maxSwaps > 0; ++it) {
            if (it->second - target <= maxSwaps) {
               maxSwaps -= (it->second - target);

               for(int i = it->second; i > target; --i) {
                  names[i] = names[i - 1];
                  ++order[names[i - 1]];
               }

               names[target] = it->first;
               ++target;
               order.erase(it->first);
               break;
            }
         }
      }
      

      cout << "Instancia " << c++ << '\n';
      for(int i = 0; i < n; ++i)
         cout << names[i] << ' ';
      cout << "\n\n";
   }
}
