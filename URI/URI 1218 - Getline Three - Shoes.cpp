#include <iostream>
#include <sstream>

using namespace std;

int main() {
   string line;
   int caseNo = 1;
   while(getline(cin, line)) {
      if(caseNo > 1)
         cout << '\n';

      istringstream input(line);

      int toSearch;
      input >> toSearch;

      getline(cin, line);

      int size;
      char gender;
      int f = 0, m = 0;

      input.str(line);
      input.clear();
      while(input >> size >> gender) {
         if(size == toSearch) {
            if(gender == 'M')
               ++m;
            else
               ++f;
         }
      }

      cout << "Caso " << caseNo << ":\n";
      cout << "Pares Iguais: " << m + f << '\n';
      cout << "F: " << f << '\n';
      cout << "M: " << m << '\n';
      ++caseNo;
   }
}
