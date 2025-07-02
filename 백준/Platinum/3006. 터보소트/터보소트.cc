#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

struct f {
    int mn, mnidx;
    int mx, mxidx;
};

int n;
int arr[100001];
f tree[262144];
int del[262144];

f gf(f a, f b) {
    f tmp;
    if (a.mn > b.mn) {
        tmp.mn = b.mn; tmp.mnidx = b.mnidx;
    } else {
        tmp.mn = a.mn; tmp.mnidx = a.mnidx;
    }
    if (a.mx > b.mx) {
        tmp.mx = a.mx; tmp.mxidx = a.mxidx;
    } else {
        tmp.mx = b.mx; tmp.mxidx = b.mxidx;
    }
    return tmp;
}

f build(int no, int s, int e) {
    if (s == e) return tree[no] = { arr[s], s, arr[s], s };
    int mid = (s + e) / 2;
    f a = build(no * 2, s, mid);
    f b = build(no * 2 + 1, mid + 1, e);
    return tree[no] = gf(a, b);
}

f upd(int no, int s, int e, int idx) {
    if (idx < s || e < idx) return tree[no];
    if (s == e) {
        del[no] = 1;  // upd2와 통합
        return tree[no] = { 987654321, 0, -1, 0 };
    }
    int mid = (s + e) / 2;
    f a = upd(no * 2, s, mid, idx);
    f b = upd(no * 2 + 1, mid + 1, e, idx);
    del[no] = del[no * 2] + del[no * 2 + 1]; // 동시에 갱신
    return tree[no] = gf(a, b);
}

f query(int no, int s, int e, int l, int r) {
    if (e < l || r < s) return { 987654321, 0, -1, 0 };
    if (l <= s && e <= r) return tree[no];
    int mid = (s + e) / 2;
    f a = query(no * 2, s, mid, l, r);
    f b = query(no * 2 + 1, mid + 1, e, l, r);
    return gf(a, b);
}

int query2(int no, int s, int e, int l, int r) {
    if (e < l || r < s) return 0;
    if (l <= s && e <= r) return del[no];
    int mid = (s + e) / 2;
    return query2(no * 2, s, mid, l, r) + query2(no * 2 + 1, mid + 1, e, l, r);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    build(1, 1, n);

    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            f mn = query(1, 1, n, 1, n);
            int d = query2(1, 1, n, 1, mn.mnidx - 1);
            upd(1, 1, n, mn.mnidx);
            cout << mn.mnidx - d - 1 << "\n";
        } else {
            f mx = query(1, 1, n, 1, n);
            int d = query2(1, 1, n, mx.mxidx + 1, n);
            upd(1, 1, n, mx.mxidx);
            cout << n - d - mx.mxidx << "\n";
        }
    }

    return 0;
}
