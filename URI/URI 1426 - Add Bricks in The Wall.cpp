#include <iostream>
#include <vector>

using namespace std;

int main() {
   vector<int> triangle[9];

   int cases;
   cin >> cases;

   for(int i = 0; i < cases; ++i) {

      for(int j = 0; j < 9; ++j) {
         triangle[j] = vector<int>(j + 1);

         if((j + 1) % 2 == 1) {
            for(int k = 0; k < j + 1; k += 2) {
               cin >> triangle[j][k];
            }
         }
      }

      for(int j = 1; j < triangle[8].size(); j += 2) {
         int left = triangle[8][j - 1],
             right = triangle[8][j + 1],
             up = triangle[6][j - 1];

         triangle[8][j] = (up - left - right) / 2;
      }

      for(int j = 7; j >= 0; --j) {
         for(int k = 0; k < triangle[j].size(); ++k) {
            triangle[j][k] = triangle[j + 1][k] + triangle[j + 1][k + 1];
         }
      }

      for(int j = 0; j < 9; ++j) {
         for(int k = 0; k < triangle[j].size(); ++k) {
            if(k > 0)
               cout << ' ';
            cout << triangle[j][k];
         }
         cout << '\n';
      }
   }
}
