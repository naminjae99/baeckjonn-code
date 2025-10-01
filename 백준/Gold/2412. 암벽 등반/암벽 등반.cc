#include <bits/stdc++.h>
using namespace std;

constexpr int INF = 1e9 + 7;
using pii = pair<int, int>;

vector<pii> v[200001]; // v[y] : (x, idx)
int x[50001], y[50001], dist[50001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; cin >> n >> m;
    v[0].push_back({0, 0});
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
        v[y[i]].push_back({x[i], i});
    }
    for (int i = 0; i <= m; i++) sort(v[i].begin(), v[i].end());

    queue<int> Q;
    Q.push(0); dist[0] = 1;

    while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        if (y[cur] == m) {
            cout << dist[cur] - 1 << '\n';
            return 0;
        }
        for (int ny = y[cur] - 2; ny <= y[cur] + 2; ny++) {
            if (ny < 0 || ny > m) continue;
            auto lo = lower_bound(v[ny].begin(), v[ny].end(), pii{x[cur] - 2, -INF});
            auto hi = lower_bound(v[ny].begin(), v[ny].end(), pii{x[cur] +3, -INF});
            for (auto it = lo; it != hi; it++) {
                auto [nx, nxt] = *it;
                if (dist[nxt]) continue;
                Q.push(nxt); dist[nxt] = dist[cur] + 1;
            }
        }
    }
    cout << -1 << '\n';
}
