#include <iostream>
#include <vector>

using namespace std;

struct SequenceValue {
   int from, to, value;

   SequenceValue(int f, int t, int v) : 
      from(f), to(t), value(v) { }
};

vector<SequenceValue> computeSequence() {
   vector<SequenceValue> result;

   result.push_back(SequenceValue(1, 1, 1));
   result.push_back(SequenceValue(2, 3, 2));
   result.push_back(SequenceValue(4, 5, 3));

   int lastTo = 5, current = 2;
   const int MAX = 2000000000;

   while(lastTo < MAX) {
      for(int i = result[current].from; i <= result[current].to; ++i) {
         result.push_back(SequenceValue(lastTo + 1, lastTo + 
                  result[current].value, i));
         lastTo = result[result.size() - 1].to;

         if (lastTo >= MAX)
            break;
      }

      ++current;
   }

   return result;
}

int main() {
   vector<SequenceValue> sequence = computeSequence();

   int n;
   while(cin >> n && n > 0) {
      int index = 0;

      while(sequence[index].to < n)
         ++index;

      cout << sequence[index].value << '\n';
   }
}
