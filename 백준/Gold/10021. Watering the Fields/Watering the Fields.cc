#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    int u, v;
    int cost;
    bool operator<(const Edge& o) const {
        return cost < o.cost;
    }
};

int n, c;
pair<int, int> pos[2005];
int parent[2005];

int find(int x) {
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

bool uni(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (parent[a] > parent[b]) swap(a, b); // union by size
    parent[a] += parent[b];
    parent[b] = a;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> c;
    for (int i = 1; i <= n; i++) {
        cin >> pos[i].first >> pos[i].second;
    }

    vector<Edge> edges;
    edges.reserve(n * (n - 1) / 2);

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int dx = pos[i].first - pos[j].first;
            int dy = pos[i].second - pos[j].second;
            int dist = dx * dx + dy * dy;
            if (dist >= c) edges.push_back({i, j, dist});
        }
    }

    sort(edges.begin(), edges.end());
    fill(parent, parent + n + 1, -1);

    int cnt = 0, result = 0;
    for (auto& e : edges) {
        if (uni(e.u, e.v)) {
            result += e.cost;
            if (++cnt == n - 1) {
                cout << result;
                return 0;
            }
        }
    }

    cout << -1;
    return 0;
}
