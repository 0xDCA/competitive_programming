#include <iostream>
#include <queue>
#include <stack>

using namespace std;

int main() {
   int n;
   while(cin >> n) {
      stack<int> s;
      queue<int> q;
      priority_queue<int> pq;

      int isStack = 1,
          isQueue = 1,
          isPriorityQueue = 1;

      for(int i = 0; i < n; ++i) {
         int op, arg;
         cin >> op >> arg;

         if (op == 1) {
            s.push(arg);
            q.push(arg);
            pq.push(arg);
         } else {
            if (s.top() != arg)
               isStack = 0;
            if (q.front() != arg)
               isQueue = 0;
            if (pq.top() != arg)
               isPriorityQueue = 0;

            s.pop();
            q.pop();
            pq.pop();
         }
      }

      int count = isStack + isQueue + isPriorityQueue;

      if (count == 0)
         cout << "impossible\n";
      else if(count > 1)
         cout << "not sure\n";
      else {
         if (isStack)
            cout << "stack\n";
         else if (isQueue)
            cout << "queue\n";
         else
            cout << "priority queue\n";
      }


   }

}
