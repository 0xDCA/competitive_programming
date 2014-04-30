#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main() {
   int t;
   cin >> t;

   for(int i = 1; i <= t; ++i) {
      int n;
      cin >> n;

      vector<int> v(n);
      for(int j = 0; j < n; ++j)
         cin >> v[j];

      sort(v.begin(), v.end());

      vector<int> optimal(2 * n + 1);

      int high = n + 1,
          low = n;

      // min, max...
      optimal[n] = v[0];
      optimal[n + 1] = v[n - 1];
      
      int currentMax = n - 2,
          currentMin = 1;

      for(int j = 0; j < n - 2; ++j) {
         int possibilities[2] = { currentMin, currentMax };

         int bestIndex = -1,
             best = -1;
         int append = 0;

         for(int k = 0; k < 2; ++k) {
            for(int w = 0; w < 2; ++w) {
               int adjacent = w == 0 ? optimal[low] : optimal[high],
                   difference = abs(v[possibilities[k]] - adjacent);
               if (bestIndex == -1 || difference > best) {
                  best = difference;
                  append = w;
                  bestIndex = k;
               }
            }
         }

         int destination;

         if (append == 0)
            destination = --low;
         else
            destination = ++high;

         int current;
         if (bestIndex == 0)
            current = currentMin++;
         else
            current = currentMax--;

         optimal[destination] = v[current];
      }

      int sum = 0;
      for(int j = low + 1; j <= high; ++j) {
         sum += abs(optimal[j] - optimal[j - 1]);
      }

      cout << "Case " << i << ": " << sum << '\n';
   }
}
