#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minFlips(vector<int>& v) {
   int result = 0;

   for(int i = v.size(); i >= 0; --i) {
      for(int j = 1; j < i; ++j) {
         if (v[j - 1] <= v[j])
            continue;
         
         swap(v[j - 1], v[j]);
         ++result;
      }
   }

   return result;
}

int main() {
   int n;
   
   while(cin >> n) {
      vector<int> v(n);
      for(int i = 0; i < n; ++i)
         cin >> v[i];

      cout << "Minimum exchange operations : " << minFlips(v) << '\n';
   }
}
