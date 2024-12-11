#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <memory.h>
#include <iomanip> 

using namespace std;

int n, m;
int arr[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int vis[51][51];
int re;
void printarr() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
void init() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            vis[i][j] = 0;
        }
    }
}
int bound(int x,int y) {
    if (x < 0 || x >= n || y < 0 || y >= m)
        return 1;
    else
        return 0;
}
void f(int a,int b) {
    int high = arr[a][b];
    init();
    queue <pair<int, int>> q;
    q.push({ a,b });
    vis[a][b] = 1;
    queue <pair<int, int>> tmp;
 
    int wall = 10;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        tmp.push({ x,y });
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (bound(nx,ny) == 1)
                return;
            if (vis[nx][ny] == 1)
                continue;
            if (arr[nx][ny] <= high) {
                q.push({ nx,ny });
                vis[nx][ny] = 1;
            }
            if (arr[nx][ny] > arr[x][y]) {
                wall = min(wall, arr[nx][ny]);
            }
        }
    }
   
    //cout << a << " , " << b << "의 tmp들\n";
    int s = tmp.size();
    for (int i = 0; i < s; i++) {
        int x= tmp.front().first;
        int y = tmp.front().second;
       // cout << x << " , " << y << "\n";
        re += wall - arr[x][y];
        arr[x][y] = wall;
        tmp.pop();
    }
}
int main() {    
    ios::sync_with_stdio(0); cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            arr[i][j] = s[j]-'0';
        }
    }
    //printarr();

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
     
            f(i, j);
            //cout <<"( " << i << ", " << j << " )" << "\n";
            //printarr();
        }
    }
    cout << re;
}