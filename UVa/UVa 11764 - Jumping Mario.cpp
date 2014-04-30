#include <iostream>

using namespace std;

int main() {
   int cases;
   cin >> cases;

   for(int i = 1; i <= cases; ++i) {
      int walls, previous = -1, low = 0, high = 0,
          current;
      cin >> walls;

      for(int j = 0; j < walls; ++j) {
         cin >> current;
         if (previous != -1) {
            if (current > previous)
               ++high;
            else if (current < previous)
               ++low;
         }

         previous = current;
      }

      cout << "Case " << i << ": " << high << " " << low << '\n';
   }
}
