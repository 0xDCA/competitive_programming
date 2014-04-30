#include <iostream>
#include <stack>

using namespace std;

int filledWater(const string& str) {
   int result = 0;

   stack<int> s;

   for(int i = 0; i < str.size(); ++i) {
      if (str[i] == '\\')
         s.push(i);
      else if(str[i] == '/' && !s.empty()) {
         result += i - s.top();
         s.pop();
      }
   }

   return result;
}

int main() {
   int n;
   cin >> n;

   for(int i = 0; i < n; ++i) {
      string str;
      cin >> str;
      cout << filledWater(str) << '\n';
   }
}
