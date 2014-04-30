#include <iostream>
#include <utility>
#include <cmath>

using namespace std;

pair<int,int> getBestConsecutive(int n) {
  int count = 1, start = n;

  int upperLimit = (int)ceil(sqrt(2 * n));

  for(int i = upperLimit; i > 1; --i) {
    int guess = (int)round((n * 1.0) / i - (i - 1) / 2.0);
    if (guess == 0)
      continue;
    if (i * (guess - 1) + i * (i + 1) / 2 == n) {
      start = guess;
      count = i;
      break;
    }
  }

  return pair<int,int>(start, start + count - 1);
}

int main(void) {
  int n;

  while(cin >> n && n > -1) {
    pair<int, int> result = getBestConsecutive(n);
    cout << n << " = " << result.first << " + ... + " << result.second << '\n';
  }
}
