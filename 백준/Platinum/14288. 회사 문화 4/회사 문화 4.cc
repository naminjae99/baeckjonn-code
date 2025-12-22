#include <iostream>
#include <vector>

using namespace std;

vector<int> child[100005];
int a[100005], b[100005], idx;
int bit1[100005], bit2[100005]; // 2개의 펜윅 트리
int n, m;

void dfs(int x) {
    a[x] = ++idx;
    for (int c : child[x]) dfs(c);
    b[x] = idx;
}

void update(int bit[], int i, int val) {
    while (i <= n) {
        bit[i] += val;
        i += i & -i;
    }
}

int query(int bit[], int i) {
    int res = 0;
    while (i > 0) {
        res += bit[i];
        i -= i & -i;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int p; cin >> p;
        if (p != -1) child[p].push_back(i);
    }

    dfs(1);

    int mode = 0; // 0: 하행, 1: 상행
    while (m--) {
        int cmd; cin >> cmd;
        if (cmd == 1) {
            int x, y; cin >> x >> y;
            if (mode == 0) {
                // 하행: 구간 업데이트 (Range Update)
                update(bit1, a[x], y);
                update(bit1, b[x] + 1, -y);
            } else {
                // 상행: 단일 업데이트 (Point Update)
                update(bit2, a[x], y);
            }
        } else if (cmd == 2) {
            int x; cin >> x;
            // 결과 = Tree1의 점 쿼리 + Tree2의 구간 쿼리
            int res1 = query(bit1, a[x]);
            int res2 = query(bit2, b[x]) - query(bit2, a[x] - 1);
            cout << res1 + res2 << "\n";
        } else {
            mode = !mode;
        }
    }
    return 0;
}