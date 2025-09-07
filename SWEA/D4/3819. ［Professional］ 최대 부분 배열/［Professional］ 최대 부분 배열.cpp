#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N;
        cin >> N;

        ll sum = 0;
        ll minSum = 0;      // 이전까지의 최소 누적합
        ll ans = LLONG_MIN; // 현재까지의 최대 부분 배열 합

        for (int i = 0; i < N; i++) {
            ll x;
            cin >> x;
            sum += x;

            ans = max(ans, sum - minSum);
            minSum = min(minSum, sum);
        }

        cout << "#" << tc << " " << ans << "\n";
    }

    return 0;
}
