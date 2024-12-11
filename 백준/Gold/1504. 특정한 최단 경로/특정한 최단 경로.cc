#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<set>
#include<unordered_map>
using namespace std;
const int INF = 2*1e9;

int n, m;
vector <pair<int, int>> e[801];
int d[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>>q;
int re[4][4];
int x, y;

void dik(int s, int cur) {
    fill(d, d + n + 1, INF);
    q.push({ 0,s });
    d[s] = 0;

    while (!q.empty()) {
        int now = q.top().second;
        int cost = -q.top().first;
        q.pop();
        if (d[now] < cost)
            continue;
        for (auto nxt : e[now]) {
            if (d[nxt.second] > cost + nxt.first) {
                d[nxt.second] = cost + nxt.first;
                q.push({ -d[nxt.second],nxt.second });

            }
        }
    }
    if (cur == 0) {
        re[0][1] = d[x];
        re[0][2] = d[y];
    }
    if (cur == 1) {
        re[1][2] = d[y];
        re[2][1] = d[y];
    }
    if (cur == 3) {

        re[1][3] = d[x];
        re[2][3] = d[y];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({ c,b });
        e[b].push_back({ c,a });
    }

    cin >> x >> y;

    dik(1, 0);
    dik(x, 1);
    dik(n, 3);

    int ma = INF;
 
    if(!(re[0][1]==INF|| re[2][1] == INF|| re[2][3] == INF))
        ma = min(ma, re[0][1] + re[1][2] + re[2][3]);
    if (!(re[0][2] == INF || re[2][1] == INF || re[1][3] == INF))
         ma = min(ma, re[0][2] + re[2][1] + re[1][3]);
    if (ma < INF)
        cout << ma;
    else
        cout << -1;
}
