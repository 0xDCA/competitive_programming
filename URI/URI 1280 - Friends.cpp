#include <iostream>
#include <map>
#include <utility>
#include <cmath>

using namespace std;

int solve(int n, int m, map<pair<int, int>, int>& cache) {
   if (m == 0)
      return n + 1;

   pair<int, int> key(n, m);
   if (cache.count(key) > 0)
      return cache[key];

   int result = 0;
   if (n == 0 && m >= 1)
      result = solve(1, m - 1, cache);
   else if(n > 0 && m > 0)
      result = solve(solve(n - 1, m, cache), m - 1, cache);

   if (m <= 3)
      result = min(result, 200);
   else if(m == 4)
      result = min(result, 2);

   cache[key] = result;
   return result;

}

int main() {
   int cases;
   cin >> cases;

   int m, n;
   map<pair<int, int>, int> cache;
   for(int i = 0; i < cases; ++i) {
      cin >> m >> n;

      cout << solve(n, m, cache) << '\n';
   }
}
