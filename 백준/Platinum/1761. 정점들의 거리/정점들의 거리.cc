#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAXN = 100005;
const int MAXLOG = 17;

vector<pair<int, int>> ed[MAXN];
int n, m;
int level[MAXN];
int par[MAXN][MAXLOG + 1];
int root_dis[MAXN];

void dfs(int now, int p, int dis) {
    level[now] = level[p] + 1;
    root_dis[now] = dis;
    par[now][0] = p;

    for (auto c : ed[now]) {
        if (c.first != p) {
            dfs(c.first, now, dis + c.second);
        }
    }
}

int lca(int u, int v) {
    if (level[u] < level[v]) swap(u, v);

    for (int i = MAXLOG; i >= 0; i--) {
        if (level[u] - (1 << i) >= level[v]) {
            u = par[u][i];
        }
    }

    if (u == v) return u;

    for (int i = MAXLOG; i >= 0; i--) {
        if (par[u][i] != 0 && par[u][i] != par[v][i]) {
            u = par[u][i];
            v = par[v][i];
        }
    }

    return par[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        ed[a].push_back({ b, c });
        ed[b].push_back({ a, c });
    }

    dfs(1, 0, 0);

    for (int j = 1; j <= MAXLOG; j++) {
        for (int i = 1; i <= n; i++) {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }

    cin >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        int ancestor = lca(a, b);
        cout << root_dis[a] + root_dis[b] - 2 * root_dis[ancestor] << '\n';
    }

    return 0;
}
