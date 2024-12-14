#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>

using namespace std;

int n, m,r;
int vis[100005];
vector<int> e1[100005];
int cnt = 2;

void f(int x) {
    
 //   cout << x << "에서\n";
    sort(e1[x].begin(), e1[x].end(),greater<>());
    for (int i = 0; i < e1[x].size(); i++) {
        if (vis[e1[x][i]] == 0) {
            vis[e1[x][i]] = cnt++;
          //  cout << e1[x][i] << "방문\n";
            f(e1[x][i]);
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
    vis[r] = 1;
    f(r);
    for (int i = 1; i <= n; i++) {
        cout << vis[i] << "\n";
    }
}
    