#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

string arabicToRoman(int arabic) {
   static int romanValues[13] = { 1000, 900, 500, 400, 100, 90, 
                                50, 40, 10, 9, 5, 4, 1 };
   static string romanStrings[13] = { "M", "CM", "D", "CD", "C", 
                                    "XC", "L", "XL", "X", "IX",
                                    "V", "IV", "I" };

   string result;
   for(int i = 0; i < 13; ++i) {
      if (arabic == 0)
         break;

      int times = arabic / romanValues[i];
      arabic -= times * romanValues[i];

      for(int j = 0; j < times; ++j)
         result += romanStrings[i];
   }

   return result;
}

int romanToArabic(const string& roman) {
   map<char, int> romanValues;
   romanValues['M'] = 1000;
   romanValues['D'] = 500;
   romanValues['C'] = 100;
   romanValues['L'] = 50;
   romanValues['X'] = 10;
   romanValues['V'] = 5;
   romanValues['I'] = 1;

   int result = 0;
   for(int i = 0; i < roman.size(); ++i) {
      int value = romanValues[roman[i]];
      if (i < roman.size() - 1 && 
            value < romanValues[roman[i + 1]])
         result -= value;
      else
         result += value;
   }

   return result;
}

bool isArabic(const string& number) {
   return number[0] >= '0' && number[0] <= '9';
}

int stringToInt(const string& number) {
   istringstream input(number);

   int result;
   input >> result;

   return result;
}

int main() {
   string number;
   while(cin >> number) {
      if (isArabic(number))
         cout << arabicToRoman(stringToInt(number)) << '\n';
      else
         cout << romanToArabic(number) << '\n';
   }
}
