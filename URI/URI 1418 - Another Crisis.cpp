#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#include <map>
#include <queue>
#include <functional>

using namespace std;

struct Employee {
   vector<int> subordinates;

   Employee() : subordinates(vector<int>()) { }
};

int findMinWorkers(const vector<Employee>& employees,
                  int current, int minPercent, vector<int>& cache) {
   if(employees[current].subordinates.size() == 0)
      return 1;

   if(cache[current] != -1)
      return cache[current];

   int n = employees[current].subordinates.size();
   int minSubordinates = (int)ceil(n * minPercent / 100.0);

   // Descending order queue
   priority_queue<int, vector<int>, greater<int> > subordinatesResults;

   for(int i = 0; i < n; ++i) {
      int subordinate = employees[current].subordinates[i];
      subordinatesResults.push(
            findMinWorkers(employees, subordinate, minPercent, cache));
   }

   int result = 0;

   for(int i = 0; i < minSubordinates; ++i) {
      result += subordinatesResults.top();
      subordinatesResults.pop();
   }

   cache[current] = result;
   return result;
}

int main() {
   int n, t;
   while(cin >> n >> t && n > 0 && t > 0) {
      vector<Employee> employees(n + 1);

      for(int i = 1; i <= n; ++i) {
         int boss;
         cin >> boss;
         employees[boss].subordinates.push_back(i);
      }

      vector<int> cache(n + 1, -1);
      cout << findMinWorkers(employees, 0, t, cache) << '\n';
   }
}
