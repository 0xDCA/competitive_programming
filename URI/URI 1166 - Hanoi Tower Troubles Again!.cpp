#include <iostream>
#include <cmath>

using namespace std;

int maxBalls[51];

bool isPerfectSquare(int n) {
   int root = (int)(sqrt(n) + 0.5);

   return root * root == n;
}

void calculateMaxBalls() {
   int lastBall[51] = { 0 };

   int next = 1;
   int peg = 0;

   while(true) {
      bool shouldUseNextPeg = true;
      for(int i = 1; i <= peg; ++i) {
         if (isPerfectSquare(lastBall[i] + next)) {
            shouldUseNextPeg = false;
            lastBall[i] = next;
         }
      }

      if (shouldUseNextPeg) {
         maxBalls[peg] = next - 1;
         lastBall[++peg] = next;

         if (peg == 51)
            break;
      }

      ++next;
   }
}

int main() {
   calculateMaxBalls();
   int t;
   cin >> t;

   for(int i = 0; i < t; ++i) {
      int n;
      cin >> n;
      cout << maxBalls[n] << '\n';
   }
}
