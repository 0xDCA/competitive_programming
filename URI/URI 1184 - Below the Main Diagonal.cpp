#include <iostream>

using namespace std;

int main() {
   char operation;
   double value;
   double sum = 0;
   
   cin >> operation;

   for(int i = 0; i < 12; ++i) {
      for(int j = 0; j < 12; ++j) {
         cin >> value;

         if (i > j)
            sum += value;
      }
   }

   cout.precision(1);
   cout.setf(ios::fixed, ios::floatfield);

   if(operation == 'S')
      cout << sum << '\n';
   else
      cout << sum / 66 << '\n';

}
