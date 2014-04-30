#include <iostream>
#include <cmath>

using namespace std;

int main() {
   cout.flags(ios::fixed);
   cout.precision(3);

   double m1, m2, m3;
   while(cin >> m1 >> m2 >> m3) {
      double s = (m1 + m2 + m3) / 2;
      double inner = s * (s - m1) * (s - m2) * (s - m3);

      double area = -1;
      if (inner > 0)
         area = 4.0 * sqrt(inner) / 3.0;

      cout << area << '\n';

   }
}
