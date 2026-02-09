#include <vector>
#include <cstring>
using namespace std;

static const int MOD = 20170805;

// dp[y][x][0] : (y,x)에 오른쪽으로 들어온 경우
// dp[y][x][1] : (y,x)에 아래쪽으로 들어온 경우
int dp[505][505][2];

int solution(int m, int n, vector<vector<int>> city_map) {
    memset(dp, 0, sizeof(dp));

    // 시작점 바로 옆에서 출발
    if (n > 1 && city_map[0][1] != 1)
        dp[0][1][0] = 1; // 오른쪽으로 이동

    if (m > 1 && city_map[1][0] != 1)
        dp[1][0][1] = 1; // 아래로 이동

    for (int y = 0; y < m; y++) {
        for (int x = 0; x < n; x++) {
            if (city_map[y][x] == 1) continue;

            // 오른쪽으로 이동
            if (x + 1 < n && city_map[y][x + 1] != 1) {
                if (city_map[y][x] == 2) {
                    dp[y][x + 1][0] = (dp[y][x + 1][0] + dp[y][x][0]) % MOD;
                } else {
                    dp[y][x + 1][0] = (dp[y][x + 1][0] + dp[y][x][0] + dp[y][x][1]) % MOD;
                }
            }

            // 아래로 이동
            if (y + 1 < m && city_map[y + 1][x] != 1) {
                if (city_map[y][x] == 2) {
                    dp[y + 1][x][1] = (dp[y + 1][x][1] + dp[y][x][1]) % MOD;
                } else {
                    dp[y + 1][x][1] = (dp[y + 1][x][1] + dp[y][x][0] + dp[y][x][1]) % MOD;
                }
            }
        }
    }

    return (dp[m - 1][n - 1][0] + dp[m - 1][n - 1][1]) % MOD;
}
