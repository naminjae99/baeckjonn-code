#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>

using namespace std;

int n, m,r;
int vis[100005];
vector<int> e1[100005];
int cnt = 2;

void f() {
    
    //cout << x << "에서\n";
  
    queue <int> q;
    q.push(r);
    vis[r] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < e1[x].size(); i++) {
            if (vis[e1[x][i]] == 0) {
                q.push({ e1[x][i] });
                vis[e1[x][i]] = cnt++;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> r;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        e1[a].push_back(b);
        e1[b].push_back(a);
    }
    for(int i=1;i<=n;i++)  
        sort(e1[i].begin(), e1[i].end());

   
    f();

    for (int i = 1; i <= n; i++) {
        cout << vis[i] << "\n";
    }
}
    