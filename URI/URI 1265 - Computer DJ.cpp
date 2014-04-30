#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getSongIndex(int n, int query) {
   if (query < n)
      return query;

   int wordSize = 1;
   int groupSize = n;

   while(query >= groupSize * wordSize) {
      query -= groupSize * wordSize;
      groupSize *= n;
      ++wordSize;
   }

   groupSize *= wordSize;
   
   int target = query,
       group = 0,
       i = 0;

   while(target != 0) {
      groupSize /= n;
      
      group = target / groupSize;
      target = target % groupSize;
      if (target % wordSize == i)
         break;

      ++i;
   }

   return group;
}

int main() {
   int n, q;
   
   while(cin >> n >> q && q > 0 && n > 0) {
      vector<string> titles(n);
      
      for(int i = 0; i < n; ++i)
         cin >> titles[i];

      for(int i = 0; i < q; ++i) {
         int query;
         cin >> query;

         cout << titles[getSongIndex(n, query - 1)] << '\n';
      }

      cout << '\n';
   }
}
