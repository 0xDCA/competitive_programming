#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct Circle {
    double x, y, radius;
};

bool overlaps(const Circle& a, const Circle& b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)) < a.radius + b.radius;
}

bool contained(const Circle& a, const Circle& b) {
    double distance = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    return fabs(a.radius - b.radius) > distance;
}

vector<int> id, size;
int max_size;

int find(int p) {
    int root = p;
    while(root != id[root])
        root = id[root];

    while(p != root) {
        int new_p = id[p];
        id[p] = root;
        p = new_p;
    }

    return root;
}

void union_op(int p, int q) {
    int i = find(p),
        j = find(q);

    if (i == j)
        return;

    if (size[i] < size[j]) {
        id[i] = j;
        size[j] += size[i];
        max_size = max(max_size, size[j]);
    } else {
        id[j] = i;
        size[i] += size[j];
        max_size = max(max_size, size[i]);
    }

}

int maxComponent(const vector<Circle>& circles) {
    int result = 1;

    max_size = circles.size() > 0 ? 1 : 0;
    id = vector<int>(circles.size());
    size = vector<int>(circles.size());

    for(int i = 0; i < id.size(); ++i) {
        id[i] = i;
        size[i] = 1;
    }

    for(int i = 0; i < circles.size(); ++i) {
        for(int j = 0; j < circles.size(); ++j) {
            if (i == j)
               continue;
            if (overlaps(circles[i], circles[j]) && 
                  !contained(circles[i], circles[j])) {
               union_op(i, j);
            }
        }
    }

    return max_size;
}

int main() {
    int n;
    while(cin >> n && n > -1) {
        vector<Circle> circles(n);

        for(int i = 0; i < n; ++i) {
            cin >> circles[i].x >> circles[i].y >> circles[i].radius;
        }

        int result = maxComponent(circles);
        cout << "The largest component contains ";
        if (result == 1)
            cout << "1 ring.\n";
        else
            cout << result << " rings.\n";
    }

    return 0;
}
