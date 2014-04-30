#include <iostream>

using namespace std;

double requestValidScore() {
   while(true) {
      double value;
      cin >> value;

      if(value <= 10.0 && value >= 1.0)
         return value;

      cout << "nota invalida\n";
   }
}

bool requestValidAction() {
   while(true) {
      cout << "novo calculo (1-sim 2-nao)\n";

      int answer;
      cin >> answer;

      if(answer == 1)
         return true;
      if(answer == 2)
         return false;
   }
}

int main() {
   cout.precision(2);
   cout.setf(ios::fixed, ios::floatfield);

   bool execute = true;
   while(execute) {
      double a = requestValidScore(),
             b = requestValidScore();

      cout << "media = " << (a + b) / 2 << '\n';

      execute = requestValidAction();
   }
}
