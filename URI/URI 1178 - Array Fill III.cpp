#include <iostream>

using namespace std;

int main() {
   double x;
   cin >> x;

   cout.precision(4);
   cout.setf(ios::fixed, ios::floatfield);

   for(int i = 0; i < 100; ++i) {
      cout << "N[" << i << "] = " << x << '\n';
      
      x /= 2.0;
   }
}
