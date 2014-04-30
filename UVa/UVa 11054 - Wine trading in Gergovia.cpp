#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;

    while(cin >> n && n > 0) {
        vector<long long> houses(n);
        for(int i = 0; i < n; ++i)
            cin >> houses[i];

        long long answer = 0;
        queue<int> q;
        for(int i = 0; i < n; ++i) {
            if (q.empty())
                q.push(i);
            else {
                if (houses[q.front()] * houses[i] < 0) {
                    while(houses[i] != 0 && !q.empty()) {
                        int t = q.front();

                        if (abs(houses[t]) > abs(houses[i])) {
                            answer += abs(houses[i]) * (i - t);
                            houses[t] += houses[i];
                            houses[i] = 0;
                            break;
                        } else {
                            answer += abs(houses[t]) * (i - t);
                            houses[i] += houses[t];
                            houses[t] = 0;
                            q.pop();
                        }
                    }

                    if (houses[i] != 0)
                        q.push(i);
                } else if(houses[q.front()] * houses[i] > 0) {
                    q.push(i);
                }
            }
        }

        cout << answer << '\n';
    }
    return 0;
}
