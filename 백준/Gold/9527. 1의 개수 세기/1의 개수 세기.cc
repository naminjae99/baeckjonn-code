#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// f(x) : 0 ~ x 까지의 구간에서 1의 개수 합
ll countOnes(ll x) {
    if (x < 0) return 0; // 안전 처리
    ll res = 0;
    for (int i = 0; i < 60; i++) { // 2^59 > 10^16
        ll cycle = (1LL << (i + 1));
        ll full = (x + 1) / cycle * (1LL << i);
        ll remain = max(0LL, (x + 1) % cycle - (1LL << i));
        res += full + remain;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m;
    cin >> n >> m;

    cout << countOnes(m) - countOnes(n - 1) << "\n";
    return 0;
}
