#include <bits/stdc++.h>
using namespace std;

struct FenwickTree {
    int n;
    vector<long long> tree;

    FenwickTree(int n) : n(n), tree(n + 1, 0) {}

    void update(int idx, long long delta) {
        while (idx <= n) {
            tree[idx] += delta;
            idx += idx & -idx;
        }
    }

    long long query(int idx) const {
        long long ret = 0;
        while (idx > 0) {
            ret += tree[idx];
            idx -= idx & -idx;
        }
        return ret;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> b[i];

    FenwickTree fenwickA(n), fenwickB(n);

    vector<pair<int, int>> visited;
    int idx = 1;
    int answer = 0;

    while (idx <= n) {
        visited.clear();
        answer++;

        int idx2 = idx;
        while (idx2 <= n) {
            long long partA = (a[idx2] > 1) ? fenwickA.query(a[idx2] - 1) : 0;
            long long partB = (b[idx2] > 1) ? fenwickB.query(b[idx2] - 1) : 0;

            if (partA != partB) break;

            fenwickA.update(a[idx2], 1);
            fenwickB.update(b[idx2], 1);
            visited.emplace_back(a[idx2], b[idx2]);

            idx2++;
        }

        // rollback
        for (auto &[x, y] : visited) {
            fenwickA.update(x, -1);
            fenwickB.update(y, -1);
        }

        idx = idx2;
    }

    cout << answer << '\n';
    return 0;
}
