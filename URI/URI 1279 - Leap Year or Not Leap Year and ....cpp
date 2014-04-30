#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int toInt(const string& num) {
   istringstream stream(num);
   int result;
   stream >> result;
   return result;
}

bool isLeapYear(const string& year) {
   int lastTwo = toInt(year.substr(year.size() - 2));
   bool divisibleBy4 = lastTwo % 4 == 0,
        divisibleBy100 = lastTwo == 0,
        divisibleBy400 = toInt(year.substr(year.size() - 4, 2)) % 4 == 0
           && lastTwo == 0;
   return divisibleBy4 && (!divisibleBy100 || divisibleBy400);
}

bool isHuluculuYear(const string& year) {
   int sum = 0;
   for(int i = 0; i < year.size(); ++i)
      sum += year[i] - '0';

   char last = year[year.size() - 1];
   return sum % 3 == 0 && (last == '0' || 
         last == '5');
}

bool isBulukuluYear(const string& year) {
   char last = year[year.size() - 1];
   bool divisibleBy5 = last == '0' || 
         last == '5';

   int sumEven = 0,
       sumOdd = 0;
   for(int i = 0; i < year.size(); ++i) {
      if (i % 2 == 0)
         sumEven += year[i] - '0';
      else
         sumOdd += year[i] - '0';
   }

   bool divisibleBy11 = (sumEven - sumOdd) % 11 == 0;
   return divisibleBy5 && divisibleBy11 && isLeapYear(year);
}

int main() {
   string year;
   bool first = true;
   while(cin >> year) {
      if (!first)
         cout << '\n';

      bool huluculu = isHuluculuYear(year),
           bulukulu = isBulukuluYear(year),
           leap = isLeapYear(year);

      if (!leap && !huluculu && !bulukulu)
         cout << "This is an ordinary year.\n";
      else {
         if (leap)
            cout << "This is leap year.\n";
         if (huluculu)
            cout << "This is huluculu festival year.\n";
         if (bulukulu)
            cout << "This is bulukulu festival year.\n";
      }

      first = false;
   }
}
