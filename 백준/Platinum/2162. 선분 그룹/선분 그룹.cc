#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int par[3005];

int find(int x) {
    if (par[x] < 0) return x;
    return par[x] = find(par[x]);
}

bool uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    par[a] += par[b];
    par[b] = a;
    return true;
}

bool isCross(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) {
    auto ccw = [](pair<int,int> a, pair<int,int> b, pair<int,int> c) {
        long long res = 1LL*(b.first - a.first)*(c.second - a.second) - 1LL*(b.second - a.second)*(c.first - a.first);
        return (res > 0) - (res < 0);
    };

    int ab = ccw(a, b, c) * ccw(a, b, d);
    int cd = ccw(c, d, a) * ccw(c, d, b);

    if (ab == 0 && cd == 0) {
        if (a > b) swap(a, b);
        if (c > d) swap(c, d);
        return c <= b && a <= d;
    }
    return ab <= 0 && cd <= 0;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int,int>> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].first >> A[i].second >> B[i].first >> B[i].second;
        par[i] = -1;
    }

    // 모든 선분 쌍 비교
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (isCross(A[i], B[i], A[j], B[j])) {
                uni(i, j);
            }
        }
    }

    int groupCount = 0, maxGroupSize = 0;
    for (int i = 0; i < n; i++) {
        if (par[i] < 0) {
            groupCount++;
            maxGroupSize = max(maxGroupSize, -par[i]);
        }
    }

    cout << groupCount << "\n" << maxGroupSize << "\n";
}
