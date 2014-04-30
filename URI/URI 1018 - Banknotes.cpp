#include <iostream>

using namespace std;

int main() {
   int n;
   cin >> n;
   cout << n << '\n';
   const int notes[7] = { 100, 50, 20, 10, 5, 2, 1 };
   int result[7]  = { 0 };
   for(int i = 0; i < 7; ++i) { 
      result[i] = n / notes[i];
      n = n % notes[i];

      cout << result[i] << " nota(s) de R$ " << notes[i] << ",00\n";
   }
}
