#include <bits/stdc++.h>
using namespace std;

const int MAX = 100005;
const int LOG = 17;

vector<int> tree[MAX];
int depth[MAX], parent[MAX][LOG];

void dfs(int cur, int par) {
    depth[cur] = depth[par] + 1;
    parent[cur][0] = par;
    for (int next : tree[cur]) {
        if (next != par) dfs(next, cur);
    }
}

void build(int n) {
    for (int j = 1; j < LOG; j++) {
        for (int i = 1; i <= n; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    for (int i = LOG - 1; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v])
            u = parent[u][i];
    }
    if (u == v) return u;
    for (int i = LOG - 1; i >= 0; i--) {
        if (parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(1, 0);
    build(n);

    int m;
    cin >> m;
    while (m--) {
        int r, u, v;
        cin >> r >> u >> v;

        int a = lca(u, v);
        int b = lca(u, r);
        int c = lca(v, r);

        // 가장 깊은 것 출력
        int answer = b;
        if (depth[a] > depth[answer]) answer = a;
        if (depth[c] > depth[answer]) answer = c;
        cout << answer << '\n';
    }
}
