#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<set>
#include<unordered_map>
using namespace std;
const int INF = 1e9;

int n, m,x,re;
vector <pair<int, int>> e[1001];
vector <pair<int, int>> r_e[1001];
int d[1001];
int dd[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>>q;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m>>x;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({ c,b });
        r_e[b].push_back({ c,a });
    }
    fill(d, d + n+1, INF);
    d[x] = 0;
    q.push({ 0,x });
    while (!q.empty()) {
        int now = q.top().second;
        int cost = -q.top().first;
        q.pop();
        if (cost > d[now])
            continue;
        for (auto i : r_e[now]) {
            if (d[i.second] > cost + i.first) {
                d[i.second] = cost + i.first;
                q.push({ -d[i.second],i.second });
            }
        }
    }
    while (!q.empty())
        q.pop();
    fill(dd, dd + n + 1, INF);
    dd[x] = 0;
    q.push({ 0,x });
    while (!q.empty()) {
        int now = q.top().second;
        int cost = -q.top().first;
        q.pop();
        if (cost > dd[now])
            continue;
        for (auto i : e[now]) {
            if (dd[i.second] > cost + i.first) {
                dd[i.second] = cost + i.first;
                q.push({ -dd[i.second],i.second });
            }
        }
    }
    int mm = -1;
    for (int i = 1; i <=n; i++) {
        if (d[i] == INF|| dd[i] == INF)
            continue;
        mm = max(mm, d[i] + dd[i]);
    }
    cout << mm;
}
