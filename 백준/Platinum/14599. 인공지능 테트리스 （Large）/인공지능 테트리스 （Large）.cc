#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include<iostream>
#include<queue>
#include<string>
#include<memory.h>
#include<algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int m, ret, n;
int arr[21][11];
int cpy[21][11];
int vis[21][11][19];

// 음수 제거 완료 (코드로 검증됨)
int blockx[19][4] = {
    {0,0,1,2},
    {0,0,0,1},
    {0,1,2,2},  // 수정: blocky {0,0,0,-1} → {1,1,1,0}
    {0,1,1,1},
    {0,0,1,2},
    {0,1,1,1},  // 수정: blocky {0,0,-1,-2} → {2,2,1,0}
    {0,1,2,2},
    {0,0,0,1},
    {0,1,2,3},
    {0,0,0,0},
    {0,0,1,1},
    {0,1,1,2},
    {1,1,1,0},  // 수정: blockx {0,0,0,-1} → {1,1,1,0}
    {0,1,1,2},  // 수정: blocky {0,-1,0,0} → {1,0,1,1}
    {0,0,0,1},  // 수정: blocky {0,1,0,-1} 없음 → bn=14가 원래 bn=15
    {0,1,1,2},
    {0,0,1,1},  // 수정: blocky {0,1,0,-1} → {1,2,1,0}
    {0,1,1,2},  // 수정: blocky {0,-1,0,-1} → {1,0,1,0}
    {0,0,1,1}
};

int blocky[19][4] = {
    {0,1,0,0},
    {0,1,2,2},
    {1,1,1,0},  // 수정
    {0,0,1,2},
    {0,1,1,1},
    {2,2,1,0},  // 수정
    {0,0,0,1},
    {0,1,2,0},
    {0,0,0,0},
    {0,1,2,3},
    {0,1,0,1},
    {0,0,1,0},
    {0,1,2,1},  // 수정
    {1,0,1,1},  // 수정
    {0,1,2,1},
    {0,0,1,1},
    {1,2,1,0},  // 수정
    {1,0,1,0},  // 수정
    {0,1,1,2}
};

bool out(int x, int y) {
    return x < 0 || x >= n || y < 0 || y >= m;
}

bool canPlace(int x, int y, int bn) {
    for (int bc = 0; bc < 4; bc++) {
        int nx = x + blockx[bn][bc];
        int ny = y + blocky[bn][bc];
        if (out(nx, ny) || arr[nx][ny]) return false;
    }
    return true;
}

void cal(int x, int y, int bn) {
    memcpy(cpy, arr, sizeof(arr));
    for (int bc = 0; bc < 4; bc++) {
        cpy[x + blockx[bn][bc]][y + blocky[bn][bc]] = 1;
    }
    int re = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < m; j++) if (cpy[i][j]) cnt++;
        if (cnt == m) re++;
    }
    ret = max(re, ret);
}

void solve() {
    for (int bn = 0; bn < 19; bn++) {
        queue<pair<int,int>> q;
        for (int j = 0; j < m; j++) {
            if (!vis[0][j][bn] && canPlace(0, j, bn)) {
                vis[0][j][bn] = 1;
                q.push({0, j});
            }
        }
        while (!q.empty()) {
            auto [a, b] = q.front(); q.pop();
            // 좌우 이동
            for (int dy : {-1, 1}) {
                int sy = b + dy;
                if (!out(a, sy) && !vis[a][sy][bn] && canPlace(a, sy, bn)) {
                    vis[a][sy][bn] = 1;
                    q.push({a, sy});
                }
            }
            // 아래 이동
            int sx = a + 1;
            if (canPlace(sx, b, bn)) {
                if (!vis[sx][b][bn]) {
                    vis[sx][b][bn] = 1;
                    q.push({sx, b});
                }
            } else {
                cal(a, b, bn); // 최종 위치
            }
        }
    }
}

int main() {
    fastio
    n = 20; m = 10;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) arr[i][j] = s[j] - '0';
    }
    solve();
    cout << ret;
}