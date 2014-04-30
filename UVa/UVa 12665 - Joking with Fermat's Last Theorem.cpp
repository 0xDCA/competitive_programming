#include <iostream>
#include <cmath>

using namespace std;

int main() {
   int x, y, current = 1;

   while(cin >> x >> y) {
      int count = 0;

      int upper = min(y, 1000);

      for(int i = x; i <= upper; ++i) {
         for(int j = x; j <= i; ++j) {
            int partial = i * i * i + j * j * j;

            if (partial / 10 > y)
               break;

            if (partial % 10 == 3)
               count += 2;
         }
      }
      
      cout << "Case " << current++ << ": " << count << '\n';
   }

   return 0;
}
