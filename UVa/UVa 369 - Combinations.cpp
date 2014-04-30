#include <iostream>
#include <map>
#include <utility>

using namespace std;

map<pair<int, int>, int> cache;

// Pascal's triangle
int combination(int n, int k) {
   if (n == k || k == 0)
      return 1;
   
   pair<int, int> entry(n, k);
   if (cache.count(entry) > 0)
      return cache[entry];

   int result = combination(n - 1, k - 1) + combination(n - 1, k);
   cache[entry] = result;
   return result;
}

int main() {
   int n, m;

   while(cin >> n >> m && n > 0 && m > 0) {
      cout << n << " things taken " << m << " at a time is " <<
         combination(n, m) << " exactly.\n";
   }
   return 0;
}
