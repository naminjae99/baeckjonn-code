#include <vector>
#include <cstring>

using namespace std;

int MOD = 20170805;
int M, N;
// dir: 0은 오른쪽(가로), 1은 아래쪽(세로)
int DY[] = { 0, 1 };
int DX[] = { 1, 0 };
int cache[500][500][2];

int dfs(int y, int x, int dir, const vector<vector<int>>& city_map) {
    // 도착 지점 도달 시 경로 1개 발견
    if (y == N - 1 && x == M - 1) {
        return 1;
    }

    int& ret = cache[y][x][dir];
    if (ret != -1) return ret;

    ret = 0;
    for (int i = 0; i < 2; i++) {
        int ny = y + DY[i];
        int nx = x + DX[i];

        // 1. 격자 범위 밖이거나 벽(1)인 경우 못 감
        if (ny < 0 || ny >= N || nx < 0 || nx >= M || city_map[ny][nx] == 1) continue;

        // 2. 현재 칸이 2(직진만 가능)인데, 들어온 방향(dir)과 나가는 방향(i)이 다르면 못 감
        if (city_map[y][x] == 2 && i != dir) continue;

        ret = (ret + dfs(ny, nx, i, city_map)) % MOD;
    }
    return ret;
}

int solution(int m, int n, vector<vector<int>> city_map) {
    N = m;
    M = n;
    
    // 캐시 초기화 (-1로 설정)
    // 프로그래머스는 여러 테스트 케이스를 돌리므로 반드시 매번 초기화해야 함
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cache[i][j][0] = cache[i][j][1] = -1;
        }
    }

    // 출발점(0,0)에서는 오른쪽으로 가는 경우와 아래로 가는 경우 두 가지를 모두 고려해야 함
    // (0,0)의 city_map은 항상 0이므로 두 방향 호출의 합이 정답
    int case1 = dfs(0, 0, 0, city_map); // 오른쪽으로 출발
    
    // 캐시를 공유하므로 출발점의 방향별 결과가 다를 수 있음. 
    // 안전하게 다시 초기화하거나, 호출 방식을 조절해야 함.
    // 여기서는 (0,0)에서 각 방향으로 나가는 것을 직접 호출하는 방식으로 수정.
    
    int path_right = 0;
    if (1 < M && city_map[0][1] != 1) path_right = dfs(0, 1, 0, city_map);
    
    int path_down = 0;
    if (1 < N && city_map[1][0] != 1) path_down = dfs(1, 0, 1, city_map);

    return (path_right + path_down) % MOD;
}