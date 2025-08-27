#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

// 전역 변수 대신 함수 내에 선언
int n, m;
char arr[105][105];
bool has_key[26];
bool visited[105][105];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

// 잠긴 문들의 위치를 저장하는 벡터
vector<pair<int, int>> locked_doors[26];

void init() {
    memset(arr, 0, sizeof(arr));
    memset(has_key, false, sizeof(has_key));
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 26; i++) {
        locked_doors[i].clear();
    }
}

void solve() {
    init();
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++) {
            arr[i][j] = s[j - 1];
        }
    }
    string s;
    cin >> s;
    if (s != "0") {
        for (char c : s) {
            has_key[c - 'a'] = true;
        }
    }

    queue<pair<int, int>> q;
    int found_docs = 0;

    // 맵의 테두리부터 탐색 시작
    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= m + 1; j++) {
            if (i == 0 || i == n + 1 || j == 0 || j == m + 1) {
                // 경계선에 해당하는 가상의 칸
                if (!visited[i][j]) {
                    q.push({ i, j });
                    visited[i][j] = true;
                }
            }
        }
    }

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || nx > n || ny < 1 || ny > m) {
                // 경계선 밖으로 나가는 경우(가상의 경계선에 접근)
                if (nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= m + 1) {
                    if (!visited[nx][ny]) {
                        q.push({ nx, ny });
                        visited[nx][ny] = true;
                    }
                }
                continue;
            }

            if (arr[nx][ny] == '*' || visited[nx][ny]) {
                continue;
            }

            char cell = arr[nx][ny];

            if (cell >= 'a' && cell <= 'z') { // 새로운 열쇠를 찾은 경우
                has_key[cell - 'a'] = true;
                visited[nx][ny] = true;
                q.push({ nx, ny });

                // 해당 열쇠로 열 수 있게 된 문들을 큐에 추가
                for (auto& p : locked_doors[cell - 'a']) {
                    if (!visited[p.first][p.second]) {
                        q.push(p);
                        visited[p.first][p.second] = true;
                    }
                }
                // 더 이상 필요 없는 문 목록은 비워줌
                locked_doors[cell - 'a'].clear();
            } else if (cell >= 'A' && cell <= 'Z') { // 잠긴 문을 만난 경우
                if (has_key[cell - 'A']) { // 열쇠가 있으면
                    visited[nx][ny] = true;
                    q.push({ nx, ny });
                } else { // 열쇠가 없으면
                    // 나중에 열쇠를 찾았을 때 다시 방문하도록 위치 저장
                    locked_doors[cell - 'A'].push_back({ nx, ny });
                }
            } else { // '.', '$'
                if (cell == '$') {
                    found_docs++;
                }
                visited[nx][ny] = true;
                q.push({ nx, ny });
            }
        }
    }
    cout << found_docs << "\n";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}