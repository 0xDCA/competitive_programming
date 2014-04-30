#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

set<string> longestCommonSubstring(const string& a, 
      const string& b) { 
   int maxLen = 0;

   vector<vector<int> > longestSuffix(a.size(), vector<int>(b.size()));
   set<string> result;

   for(int i = 0; i < a.size(); ++i) {
      for(int j = 0; j < b.size(); ++j) {
         if (a[i] == b[j]) {
            int &current = longestSuffix[i][j];
            current = i == 0 || j == 0 ? 1 : 
               longestSuffix[i - 1][j - 1] + 1;

            int from = i - current + 1;

            if (current > maxLen) {
               result.clear();
               result.insert(a.substr(from, current));
               maxLen = current;
            } else if (current == maxLen) {
               result.insert(a.substr(from, current));
            }
         }
      }
   }

   return result;
}

int main() {
   string a, b;
   bool first = true;

   while(cin >> a >> b) {
      if (!first)
         cout << '\n';
      else
         first = false;

      set<string> result = longestCommonSubstring(a, b);

      if (result.empty())
         cout << "No common sequence.\n";
      else {
         for(set<string>::const_iterator it = result.begin();
               it != result.end(); ++it)
            cout << *it << '\n';
      }
   }
}
