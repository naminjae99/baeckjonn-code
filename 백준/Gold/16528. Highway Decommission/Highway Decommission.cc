#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;
struct Edge {
    int to;
    ull len, cost;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m; 
    if (!(cin >> n >> m)) return 0;

    vector<vector<Edge>> g(n+1);
    g.reserve(n+1);

    for (int i = 0; i < m; ++i) {
        int a, b; ull L, C;
        cin >> a >> b >> L >> C;
        // 같은 (a,b,L)에서 더 싼 C만 유지하려면 별도 압축 가능하지만 필수는 아님
        g[a].push_back({b, L, C});
        g[b].push_back({a, L, C});
    }

    const ull INF = (1ULL<<62);

    // 1) 길이만으로 다익스트라
    vector<ull> dist(n+1, INF);
    priority_queue<pair<ull,int>, vector<pair<ull,int>>, greater<pair<ull,int>>> pq;
    dist[1] = 0;
    pq.push({0,1});
    while(!pq.empty()){
        auto [d,u] = pq.top(); pq.pop();
        if (d != dist[u]) continue;
        for (auto &e : g[u]) {
            ull nd = d + e.len;
            if (dist[e.to] > nd) {
                dist[e.to] = nd;
                pq.push({nd, e.to});
            }
        }
    }

    // 2) 각 노드별, SPT에 들어갈 수 있는 간선 중 유지비 최솟값 선택
    vector<ull> best(n+1, INF);
    best[1] = 0; // 수도는 합산 제외
    for (int u = 1; u <= n; ++u) {
        for (auto &e : g[u]) {
            int v = e.to;
            ull L = e.len, C = e.cost;
            if (dist[u] + L == dist[v]) {
                // u -> v 방향으로 최단경로에 올라탈 수 있음
                if (best[v] > C) best[v] = C;
            }
            if (dist[v] + L == dist[u]) {
                // v -> u 방향
                if (best[u] > C) best[u] = C;
            }
        }
    }

    // 3) 합산
    ull ans = 0;
    for (int v = 2; v <= n; ++v) {
        // 연결 그래프라면 반드시 하나는 갱신됨
        ans += best[v];
    }
    cout << ans << '\n';
    return 0;
}
