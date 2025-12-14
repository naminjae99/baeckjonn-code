#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr)

int n, m;
int tree[400005];

// 세그 트리 초기화
int build(int nd, int s, int e) {
    if (s == e) return tree[nd] = 1;
    int mid = (s + e) >> 1;
    return tree[nd] =
        build(nd << 1, s, mid) +
        build((nd << 1) + 1, mid + 1, e);
}

// k번째 살아있는 사람 찾기
int kth(int nd, int s, int e, int k) {
    if (s == e) return s;

    int left = tree[nd << 1];
    int mid = (s + e) >> 1;

    if (left >= k)
        return kth(nd << 1, s, mid, k);
    return kth((nd << 1) + 1, mid + 1, e, k - left);
}

// 사람 제거
void remove_person(int nd, int s, int e, int idx) {
    if (idx < s || idx > e) return;
    if (s == e) {
        tree[nd] = 0;
        return;
    }
    int mid = (s + e) >> 1;
    remove_person(nd << 1, s, mid, idx);
    remove_person((nd << 1) + 1, mid + 1, e, idx);
    tree[nd] = tree[nd << 1] + tree[(nd << 1) + 1];
}

int main() {
    fastio;

    cin >> n >> m;
    build(1, 1, n);

    cout << "<";

    int cur = m;
    int alive = n;

    while (alive) {
        cur = (cur - 1) % alive + 1;

        int num = kth(1, 1, n, cur);
        cout << num;

        remove_person(1, 1, n, num);
        alive--;

        if (alive == 0) {
            cout << ">";
            break;
        }

        cout << ", ";
        cur += m - 1;
    }

    return 0;
}
