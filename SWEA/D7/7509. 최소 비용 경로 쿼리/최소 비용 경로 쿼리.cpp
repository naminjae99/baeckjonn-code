#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int SZ = 1 << 14; 
const long long INF_LL = 0x3f3f3f3f3f3f3f3fLL;

int H, W, Q;
int C[10005][3];
long long tree[2 * SZ][3][3]; // 10000 * 9 대신 3*3 구조로 변경
long long L_extra[10005], R_extra[10005];

// 두 3x3 최단거리 행렬을 합치는 함수
void merge_matrix(long long res[3][3], const long long left[3][3], const long long right[3][3]) {
    long long temp[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            temp[i][j] = INF_LL;
            for (int k = 0; k < 3; k++) {
                if (left[i][k] != INF_LL && right[k][j] != INF_LL) {
                    temp[i][j] = min(temp[i][j], left[i][k] + right[k][j]);
                }
            }
        }
    }
    // 결과를 res에 복사
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            res[i][j] = temp[i][j];
}

// 구간 쿼리 (비재귀 방식)
void get_range_min(long long ret[3][3], int s, int e) {
    long long r_left[3][3], r_right[3][3];
    bool left_init = false, right_init = false;

    for (s += SZ, e += SZ; s <= e; s >>= 1, e >>= 1) {
        if (s & 1) {
            if (!left_init) {
                for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) r_left[i][j] = tree[s][i][j];
                left_init = true;
            } else {
                merge_matrix(r_left, r_left, tree[s]);
            }
            s++;
        }
        if (!(e & 1)) {
            if (!right_init) {
                for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) r_right[i][j] = tree[e][i][j];
                right_init = true;
            } else {
                merge_matrix(r_right, tree[e], r_right);
            }
            e--;
        }
    }

    if (!left_init) {
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) ret[i][j] = r_right[i][j];
    } else if (!right_init) {
        for (int i = 0; i < 3; i++) for (int j = 0; j < 3; j++) ret[i][j] = r_left[i][j];
    } else {
        merge_matrix(ret, r_left, r_right);
    }
}

void solve(int tc) {
    if (!(cin >> H >> W >> Q)) return;
    
    // 초기화
    for (int i = 0; i < 2 * SZ; i++) {
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                tree[i][j][k] = INF_LL;
    }

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> C[i][j];
        for (int j = W; j < 3; j++) C[i][j] = 1e9 + 7;

        // Leaf 노드: 행 내 이동
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                long long sum = 0;
                for (int l = min(j, k); l <= max(j, k); l++) sum += C[i][l];
                tree[SZ + i][j][k] = sum;
            }
        }
    }

    // 외곽 경로(U턴 경로) 미리 계산
    if (W == 3) {
        L_extra[0] = (long long)C[0][0] + C[0][1] + C[0][2];
        for (int i = 1; i < H; i++) 
            L_extra[i] = min(L_extra[i - 1], (long long)C[i][1]) + C[i][0] + C[i][2];
        
        R_extra[H - 1] = (long long)C[H - 1][0] + C[H - 1][1] + C[H - 1][2];
        for (int i = H - 2; i >= 0; i--) 
            R_extra[i] = min(R_extra[i + 1], (long long)C[i][1]) + C[i][0] + C[i][2];
    }

    // 트리 구축
    for (int n = SZ - 1; n > 0; n--) {
        merge_matrix(tree[n], tree[2 * n], tree[2 * n + 1]);
    }

    long long total_ans = 0;
    while (Q--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--; y1--; x2--; y2--;
        
        if (x1 > x2) { swap(x1, x2); swap(y1, y2); }

        long long temp_res[3][3];
        get_range_min(temp_res, x1, x2);
        long long res = temp_res[y1][y2];

        if (W == 3) {
            // 정답 코드의 외곽 경로 보정 로직
            if (y1 != 1 && y2 != 1) res = min(res, temp_res[2 - y1][2 - y2] + L_extra[x1] - C[x1][2 - y1] + R_extra[x2] - C[x2][2 - y2]);
            if (y1 != 1) res = min(res, temp_res[2 - y1][y2] + L_extra[x1] - C[x1][2 - y1]);
            if (y2 != 1) res = min(res, temp_res[y1][2 - y2] + R_extra[x2] - C[x2][2 - y2]);
        }
        total_ans += res;
    }

    cout << "#" << tc << " " << total_ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    if (!(cin >> T)) return 0;
    for (int t = 1; t <= T; t++) solve(t);
    return 0;
}