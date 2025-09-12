#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;
using ll = long long;

// 이동 방향 (상, 하, 좌, 우)
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

// 전역 변수
int n, m, k;
int grid[505][505];
bool visited[505][505];
pair<int, int> rect1[2]; // 첫 번째 직사각형 (왼쪽 위, 오른쪽 아래)
pair<int, int> rect2[2]; // 두 번째 직사각형 (왼쪽 위, 오른쪽 아래)
ll total_pairs = 0;

// BFS를 이용해 연결 요소를 탐색하고 직사각형 내의 칸 수를 계산하는 함수
pair<ll, ll> bfs(int start_x, int start_y) {
    // 큐를 사용하여 BFS 탐색을 수행
    queue<pair<int, int>> q;
    q.push({ start_x, start_y });
    visited[start_x][start_y] = true;

    ll count1 = 0; // 첫 번째 직사각형에 포함된 칸 수
    ll count2 = 0; // 두 번째 직사각형에 포함된 칸 수

    // BFS 탐색
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 현재 칸이 첫 번째 직사각형에 속하는지 확인
        if (x >= rect1[0].first && x <= rect1[1].first && y >= rect1[0].second && y <= rect1[1].second) {
            count1++;
        }
        // 현재 칸이 두 번째 직사각형에 속하는지 확인
        if (x >= rect2[0].first && x <= rect2[1].first && y >= rect2[0].second && y <= rect2[1].second) {
            count2++;
        }

        // 4가지 방향으로 인접한 칸 탐색
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 격자 범위와 방문 여부, 장애물 여부 확인
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !visited[nx][ny] && grid[nx][ny] == 0) {
                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }
    return { count1, count2 };
}

void solve() {
    // 전체 격자 순회
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // 방문하지 않았고 장애물이 아닌 칸에서 BFS 시작
            if (grid[i][j] == 0 && !visited[i][j]) {
                pair<ll, ll> counts = bfs(i, j);

                // 현재 연결 요소가 두 직사각형에 모두 걸쳐있는 경우
                if (counts.first > 0 && counts.second > 0) {
                    total_pairs += counts.first * counts.second;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // 입력 받기
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int r, c;
        cin >> r >> c;
        grid[r][c] = 1; // 장애물 표시
    }
    cin >> rect1[0].first >> rect1[0].second >> rect1[1].first >> rect1[1].second;
    cin >> rect2[0].first >> rect2[0].second >> rect2[1].first >> rect2[1].second;

    // 문제 해결 함수 호출
    solve();

    // 결과 출력
    cout << total_pairs << endl;

    return 0;
}
