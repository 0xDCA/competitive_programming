#include <iostream>

using namespace std;

int main() {
   long long values[5];
   int even = 0, positive = 0, negative = 0;
   for(int i = 0; i < 5; ++i) {
      cin >> values[i];
      if(values[i] % 2 == 0)
         ++even;
      if(values[i] > 0)
         ++positive;
      else if(values[i] < 0)
         ++negative;
   }

   cout << even << " valor(es) par(es)\n";
   cout << 5 - even << " valor(es) impar(es)\n";
   cout << positive << " valor(es) positivo(s)\n";
   cout << negative << " valor(es) negativo(s)\n";

}
