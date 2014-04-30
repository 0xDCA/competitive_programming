#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

long long factorial[21];

void computeFactorial() {
   factorial[0] = 1;
   for(int i = 1; i < 21; ++i)
      factorial[i] = factorial[i - 1] * i;
}

string getPermutation(const string& source, long long permutation) {
   string result(source);
   
   for(int i = 0; i < source.size(); ++i) {
      sort(result.begin() + i, result.end());
      if (permutation == 0)
         break;
      int charPos = i + permutation / factorial[source.size() - i - 1];
      swap(result[i], result[charPos]);
      permutation = permutation % factorial[source.size() - i - 1];
   }

   return result;
}

int main() {
   computeFactorial();
   int n;
   cin >> n;

   for(int i = 0; i < n; ++i) {
      string source;
      long long permutation;

      cin >> source >> permutation;
      cout << getPermutation(source, permutation) << '\n';
   }
}
