#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <cmath>

using namespace std;

vector<vector<int> > cache;
string a, b;

int minOperations(int pos_a, int pos_b) {
   // If we reached the end of a...
   if (pos_a == a.size()) {
      // we can only add the remaining characters
      return b.size() - pos_b;
   }

   // If we reached the end of b...
   if (pos_b == b.size()) {
      // we can only delete the remaining characters
      return a.size() - pos_a;
   }

   int &result = cache[pos_a][pos_b];

   if (result == -1) {
      // No operation or change...
      if (a[pos_a] == b[pos_b])
         result = minOperations(pos_a + 1, pos_b + 1);
      else {
         // Deletion
         result = 1 + minOperations(pos_a + 1, pos_b);
      
         // Insertion
         result = min(result, 1 + minOperations(pos_a, pos_b + 1));

         // Change
         result = min(result, 1 + minOperations(pos_a + 1, pos_b + 1));
      }
   }
   
   return result;
}

int main() {
   int len_a, len_b;

   while(cin >> len_a >> a >> len_b >> b) {
      cache = vector<vector<int> >(len_a, vector<int>(len_b, -1));

      cout << minOperations(0, 0) << '\n';
   }
}
