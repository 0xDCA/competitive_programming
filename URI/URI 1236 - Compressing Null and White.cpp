#include <iostream>
#include <cmath>

using namespace std;

string compress(char toCompress, int times) {
   string result;

   if(times > 2) {
      char compressChar = toCompress == ' ' ? '$' : '#';

      while(times > 0) {
         result.push_back(compressChar);
         result.push_back((char)min(255, times));
         times -= 255;
      }
   } else 
      result.append(times, toCompress);

   return result;
}

int main() {
   int n;
   cin >> n;
   string line;
   getline(cin, line);

   for(int i = 0; i < n; ++i) {
      getline(cin, line);
      
      string out;
      int lastStart = -1;
      for(int j = 0; j < line.size(); ++j) {
         if(lastStart != -1 && line[j] != line[j - 1]) {
            out += compress(line[j - 1], j - lastStart);
            lastStart = -1;
         }

         if(line[j] == ' ' || line[j] == '0')
            lastStart = lastStart == -1 ? j : lastStart;
         else
            out.push_back(line[j]);
      }

      if(lastStart != -1)
         out += compress(line[lastStart], line.size() - lastStart);

      cout << out << '\n';
   }
}
