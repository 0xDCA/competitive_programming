#include <iostream>
#include <map>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

struct Order {
   string name;
   int start, duration, price;

   bool operator<(const Order other) const {
      return start < other.start;
   }
};

bool overlap(const Order& a, const Order& b) {
   return b.start < a.start + a.duration;
}

int getNextOrder(int from, const vector<Order>& orders) {
   Order fromOrder = orders[from];
   for(int i = from + 1; i < orders.size(); ++i)
      if(!overlap(fromOrder, orders[i]))
         return i;
   return -1;
}

int bestProfit(int i, const vector<Order>& orders,
      map<int, int>& cache) {
   if (i < 0 || i >= orders.size())
      return 0;

   if (cache.count(i) > 0)
      return cache[i];

   int next = getNextOrder(i, orders);
   int result;

   int a = bestProfit(i + 1, orders, cache),
       b = bestProfit(next, orders, cache) + orders[i].price;
   result = a > b ? a : b;

   cache[i] = result;
   return result;
}

int main() {
   bool printed = false;
   int n_orders;

   while(cin >> n_orders) {
      string line;
      vector<Order> orders(n_orders);

      getline(cin, line);

      for(int i = 0; i < n_orders; ++i) {
         getline(cin, line);
         istringstream stream(line);
         Order o;
         stream >> o.name >> o.start >> o.duration >> o.price;
         orders.push_back(o);
      }

      sort(orders.begin(), orders.end());
      map<int, int> cache;
      if (printed)
         cout << '\n';
      printed = true;
      cout << bestProfit(0, orders, cache) << '\n';
   }

   return 0;
}
