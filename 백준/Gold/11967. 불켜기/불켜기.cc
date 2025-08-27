#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

// 전역 변수 대신 함수 내에 선언하여 사용
int n, m;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// (x, y)에서 켤 수 있는 불의 위치를 저장
vector<pair<int, int>> switches[105][105];

void solve() {
    // 변수 초기화
    memset(switches, 0, sizeof(switches));

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        switches[x][y].push_back({a, b});
    }

    bool lit[105][105] = {false, };
    bool visited[105][105] = {false, };
    
    queue<pair<int, int>> q;
    int lit_count = 1;

    q.push({1, 1});
    lit[1][1] = true;
    visited[1][1] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 1. 현재 방에서 켤 수 있는 불들을 모두 켠다.
        for (auto& p : switches[x][y]) {
            if (!lit[p.first][p.second]) {
                lit[p.first][p.second] = true;
                lit_count++;
                
                // 2. 불이 새로 켜진 방의 인접한 방을 확인
                for (int i = 0; i < 4; i++) {
                    int nx = p.first + dx[i];
                    int ny = p.second + dy[i];

                    if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                        // 새로 켜진 방의 주변에 이미 방문했던 방이 있다면
                        // 이 방에서 다시 탐색을 시작할 수 있게 큐에 추가
                        if (visited[nx][ny] && !visited[p.first][p.second]) {
                            q.push(p);
                            visited[p.first][p.second] = true;
                            // 큐에 추가했으므로 더 이상 주변 탐색할 필요 없음
                            break; 
                        }
                    }
                }
            }
        }
        
        // 3. 현재 방에서 불이 켜져 있고, 아직 방문하지 않은 인접한 방으로 이동한다.
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if (nx >= 1 && nx <= n && ny >= 1 && ny <= n) {
                if (lit[nx][ny] && !visited[nx][ny]) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    cout << lit_count << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    solve();

    return 0;
}