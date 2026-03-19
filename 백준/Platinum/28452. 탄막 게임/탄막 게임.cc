#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 캐릭터 이동 방향: 8방향 + 제자리(9번째)
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1, 0};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1, 0};

struct State {
    int x, y, t;
};

int N, M, T, K;
int startX, startY;
vector<pair<int, int>> bullets;
bool visited[101][101][101]; // [시간][x][y]

// 특정 시간 t에 (x, y) 좌표가 안전한지 확인하는 함수
bool is_safe(int x, int y, int t) {
    for (auto& b : bullets) {
        // 체비쇼프 거리: max(|x1-x2|, |y1-y2|)
        // 이 거리가 t 이하라면 총알이 t초 안에 해당 위치에 도달할 수 있다는 뜻
        if (max(abs(b.first - x), abs(b.second - y)) <= t) {
            return false;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M >> T;
    cin >> startX >> startY;
    cin >> K;

    for (int i = 0; i < K; i++) {
        int r, c;
        cin >> r >> c;
        bullets.push_back({r, c});
    }

    // 0초에 시작 위치가 안전한지 확인 (문제 조건상 겹치지 않지만 안전을 위해)
    if (!is_safe(startX, startY, 0)) {
        cout << "NO" << endl;
        return 0;
    }

    queue<State> q;
    q.push({startX, startY, 0});
    visited[0][startX][startY] = true;

    while (!q.empty()) {
        State cur = q.front();
        q.pop();

        // T초 동안 살아남았다면 승리
        if (cur.t == T) {
            cout << "YES" << endl;
            return 0;
        }

        // 캐릭터가 다음 초(t+1)에 이동할 수 있는 9가지 위치 탐색
        for (int i = 0; i < 9; i++) {
            int nx = cur.x + dx[i];
            int ny = cur.y + dy[i];
            int nt = cur.t + 1;

            if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
                // 아직 방문하지 않았고, nt초에 해당 위치가 총알로부터 안전하다면
                if (!visited[nt][nx][ny] && is_safe(nx, ny, nt)) {
                    visited[nt][nx][ny] = true;
                    q.push({nx, ny, nt});
                }
            }
        }
    }

    // 모든 경로를 탐색했으나 T초에 도달하지 못한 경우
    cout << "NO" << endl;

    return 0;
}