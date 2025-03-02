#include <iostream>
using namespace std;
using ll = long long;

int n, m, k;
ll arr[1000001];
ll tree[4000001];

ll init(int N, int st, int en) {  // ✅ 반환형 ll
    if (st == en)
        return tree[N] = arr[st];

    int mid = (st + en) / 2;
    return tree[N] = init(2 * N, st, mid) + init(2 * N + 1, mid + 1, en);
}

ll query(int N, int st, int en, int l, int r) {
    if (st > r || en < l)
        return 0;
    if (st >= l && en <= r)
        return tree[N];

    int mid = (st + en) / 2;
    return query(2 * N, st, mid, l, r) + query(2 * N + 1, mid + 1, en, l, r);
}

void update(int N, int st, int en, int x, ll diff) {
    if (st > x || en < x)
        return;
    if (st == en) {
        tree[N] += diff;
        return;
    }

    int mid = (st + en) / 2;
    update(2 * N, st, mid, x, diff);
    update(2 * N + 1, mid + 1, en, x, diff);
    tree[N] = tree[2 * N] + tree[2 * N + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    init(1, 1, n);

    int cmd, a;
    ll b;
    for (int i = 0; i < m + k; i++) {
        cin >> cmd >> a >> b;
        if (cmd == 1) {
            ll diff = b - arr[a];  // ✅ 변경할 값과 기존 값의 차이 계산
            arr[a] = b;  // ✅ 실제 배열 값도 변경
            update(1, 1, n, a, diff);  // ✅ 차이값을 전달
        } else {
            cout << query(1, 1, n, a, b) << "\n";
        }
    }
}
