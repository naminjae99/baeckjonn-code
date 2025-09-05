#include <bits/stdc++.h>
using namespace std;

int dx[9] = {-1,1,0,0,-1,-1,1,1,0};
int dy[9] = {0,0,1,-1,-1,1,-1,1,0};
vector<string> board(8);

bool wall(int x, int y, int t) {
    int nx = x - t; // 시간 t가 흐르면 벽이 아래로 t만큼 내려옴
    return (nx >= 0 && board[nx][y] == '#');
}

int bfs() {
    queue<pair<int,int>> q;
    q.push({7,0});

    for (int t = 0; t < 64; t++) { // 최대 64번만 확인하면 충분 (8*8)
        int qs = q.size();
        vector<vector<int>> vis(8, vector<int>(8,0));
        while (qs--) {
            auto [x,y] = q.front(); q.pop();
            if (x == 0 && y == 7) return 1; // 목표 도달
            if (wall(x,y,t)) continue;       // 현재 위치에 벽 있으면 skip

            for (int d=0; d<9; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx<0 || nx>=8 || ny<0 || ny>=8) continue;
                if (wall(nx,ny,t) || wall(nx,ny,t+1)) continue; 
                if (!vis[nx][ny]) {
                    vis[nx][ny] = 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i=0;i<8;i++) cin >> board[i];
    cout << bfs();
}
