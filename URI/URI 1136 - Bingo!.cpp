#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canCallOutAll(const vector<int>& balls, int n) {
   vector<bool> checked(n + 1, false);
   checked[0] = true;

   for(int i = 0; i < balls.size(); ++i)
      for(int j = 0; j < i; ++j)
         checked[balls[i] - balls[j]] = true;

   for(int i = 0; i < n + 1; ++i)
      if (!checked[i])
         return false;

   return true;
}

int main() {
   int n, ballNumber;

   while(cin >> n >> ballNumber && n > 0 && ballNumber > 0) {
      vector<int> balls(ballNumber);

      for(int i = 0; i < ballNumber; ++i)
         cin >> balls[i];

      sort(balls.begin(), balls.end());

      cout << (canCallOutAll(balls, n) ? 'Y' : 'N') << '\n';
   }
}
