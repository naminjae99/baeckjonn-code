#include <bits/stdc++.h>
using namespace std;
using pii = pair<long long, int>;
const long long INF = 1e15;

int N, M;
struct Edge {
    int to;
    long long w;
};
vector<Edge> adj[105];
long long dist[105];
int parent[105];

long long dijkstra(int start, int end) {
    fill(dist, dist + N + 1, INF);
    fill(parent, parent + N + 1, -1);
    priority_queue<pii, vector<pii>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        auto [cd, u] = pq.top(); pq.pop();
        if (cd > dist[u]) continue;
        for (auto &e : adj[u]) {
            int v = e.to;
            long long nd = cd + e.w;
            if (nd < dist[v]) {
                dist[v] = nd;
                parent[v] = u;
                pq.push({nd, v});
            }
        }
    }
    return dist[end];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    vector<tuple<int, int, long long>> edges;
    for (int i = 0; i < M; i++) {
        int a, b;
        long long l;
        cin >> a >> b >> l;
        adj[a].push_back({b, l});
        adj[b].push_back({a, l});
        edges.push_back({a, b, l});
    }

    // 원래 최단 경로 계산
    long long original = dijkstra(1, N);

    // 최단 경로 간선 목록 추출
    vector<pair<int, int>> pathEdges;
    int cur = N;
    while (parent[cur] != -1) {
        pathEdges.push_back({parent[cur], cur});
        cur = parent[cur];
    }

    long long maxIncrease = 0;

    // 각 최단 경로 간선에 대해 시뮬레이션
    for (auto [u, v] : pathEdges) {
        // 해당 간선의 길이를 2배로
        for (auto &e : adj[u]) if (e.to == v) e.w *= 2;
        for (auto &e : adj[v]) if (e.to == u) e.w *= 2;

        long long newDist = dijkstra(1, N);
        maxIncrease = max(maxIncrease, newDist - original);

        // 길이 복구
        for (auto &e : adj[u]) if (e.to == v) e.w /= 2;
        for (auto &e : adj[v]) if (e.to == u) e.w /= 2;
    }

    cout << maxIncrease << "\n";
}
