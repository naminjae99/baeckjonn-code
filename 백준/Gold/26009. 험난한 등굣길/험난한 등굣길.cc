#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <queue>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int n, m, k;
// 메모리 제한을 고려하여 3005 크기의 배열 사용
// 누적 합 계산 시 범위를 벗어나지 않도록 여유 있게 선언
int arr[3005][3005]; 
int vis[3005][3005];

void solve() {
    cin >> n >> m >> k;

    while (k--) {
        int r, c, d;
        cin >> r >> c >> d;
        r--; c--; // 0-based index로 변환

        // 마름모 형태의 장애물 범위를 행(row)별로 처리
        for (int i = -d; i <= d; i++) {
            int cur_r = r + i;
            if (cur_r < 0 || cur_r >= n) continue;

            int dist = d - abs(i);
            int start_c = max(0, c - dist);
            int end_c = min(m - 1, c + dist);

            // 누적 합 마킹: 시작점 +1, 끝점 다음 칸 -1
            arr[cur_r][start_c] += 1;
            arr[cur_r][end_c + 1] -= 1;
        }
    }

    // 각 행별로 누적 합을 계산하여 장애물(1) 확정
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            sum += arr[i][j];
            if (sum > 0) arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }

    // 출발지나 목적지가 장애물인 경우 예외 처리
    if (arr[0][0] == 1 || arr[n - 1][m - 1] == 1) {
        cout << "NO";
        return;
    }

    // BFS 탐색
    memset(vis, -1, sizeof(vis));
    queue<pair<int, int>> q;
    
    q.push({ 0, 0 });
    vis[0][0] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == n - 1 && y == m - 1) {
            cout << "YES\n" << vis[x][y];
            return;
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (vis[nx][ny] != -1 || arr[nx][ny] == 1) continue;

            vis[nx][ny] = vis[x][y] + 1;
            q.push({ nx, ny });
        }
    }

    cout << "NO";
}

int main() {
    fastio;
    solve();
    return 0;
}