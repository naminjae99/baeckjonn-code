#include <iostream>
#include <queue>

#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

// 좌표가 음수로 갈 수 있으므로 +1000 오프셋을 위해 크기를 넉넉히 3000으로 잡음
bool grid[3000][3000]; 
int n;
int ans = 0; // 현재 존재하는 인공 소의 수
queue<pair<int, int>> q; // 연쇄 반응을 처리할 큐

// 특정 위치 주변의 소 개수를 세는 함수
int count_adj(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        if (grid[x + dx[i]][y + dy[i]]) cnt++;
    }
    return cnt;
}

// 해당 좌표의 소가 '편안한 소'인지 확인하고 빈칸을 채우는 함수
void evaluate_and_add(int x, int y) {
    if (!grid[x][y]) return; // 정작 본인 자리에 소가 없으면 패스
    
    // 주변에 소가 정확히 3마리라면 (편안한 소라면)
    if (count_adj(x, y) == 3) {
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            // 빈 공간을 찾아서 인공 소를 추가!
            if (!grid[nx][ny]) { 
                grid[nx][ny] = true;
                ans++; // 인공 소 카운트 증가
                q.push({nx, ny}); // 방금 추가된 인공 소 때문에 또 연쇄반응이 일어날 수 있으니 큐에 삽입
                return;
            }
        }
    }
}

void input() {
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        
        // 음수 좌표를 양수로 만들기 위해 1000씩 더함
        x += 1000; 
        y += 1000;
        
        if (grid[x][y]) {
            // 이미 인공 소가 놓여있던 자리라면?
            // 이제 '진짜 소'로 대체되었으므로 굳이 주변 탐색을 할 필요 없이 인공 소 개수만 -1 해줌
            ans--;
        } else {
            // 완전 빈 공간에 새로 놓인 진짜 소라면
            grid[x][y] = true;
            q.push({x, y});
        }
        
        // 큐가 빌 때까지 주변 연쇄반응 확인
        while (!q.empty()) {
            auto [cx, cy] = q.front();
            q.pop();
            
            // 1. 방금 놓은 소 본인이 편안한 소인지 확인
            evaluate_and_add(cx, cy);
            
            // 2. 방금 놓은 소 때문에 상하좌우의 소들이 편안한 소가 되었는지 확인
            for (int dir = 0; dir < 4; dir++) {
                evaluate_and_add(cx + dx[dir], cy + dy[dir]);
            }
        }
        
        cout << ans << "\n";
    }
}

int main() {
    fastio
    input();
    return 0;
}