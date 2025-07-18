#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX = 100001;
int parent[MAX][18]; // 2^17 = 131072 > 100000
int depth[MAX];
vector<int> tree[MAX];
int n, m;

void dfs(int cur, int par) {
    depth[cur] = depth[par] + 1;
    parent[cur][0] = par;

    for (int next : tree[cur]) {
        if (next != par) {
            dfs(next, cur);
        }
    }
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);

    // 1. u를 v와 같은 depth로 올리기
    for (int i = 17; i >= 0; i--) {
        if (depth[u] - (1 << i) >= depth[v])
            u = parent[u][i];
    }

    // 2. 같아지면 LCA
    if (u == v) return u;

    // 3. 공통 조상까지 동시에 점프
    for (int i = 17; i >= 0; i--) {
        if (parent[u][i] != 0 && parent[u][i] != parent[v][i]) {
            u = parent[u][i];
            v = parent[v][i];
        }
    }

    return parent[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    dfs(1, 0);

    // parent[x][i] = x의 2^i번째 부모
    for (int j = 1; j < 18; j++) {
        for (int i = 1; i <= n; i++) {
            parent[i][j] = parent[parent[i][j - 1]][j - 1];
        }
    }

    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}
