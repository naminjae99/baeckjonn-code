#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>

using namespace std;

int n, m,r;
int vis[105];
vector<int> e1[105];
int cnt = 0;

void f() {
    
    //cout << x << "에서\n";
  
    queue <int> q;
    q.push(1);
    vis[1] = 1;

    while (!q.empty()) {
        int x = q.front();
        q.pop();
     
       
        for (int i = 0; i < e1[x].size(); i++) {
            if (vis[e1[x][i]] == 0) {
                q.push({ e1[x][i] });
                vis[e1[x][i]] = 1;
                cnt++;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        e1[a].push_back(b);
        e1[b].push_back(a);
    }
   
    f();


        cout <<cnt;
    
}
    