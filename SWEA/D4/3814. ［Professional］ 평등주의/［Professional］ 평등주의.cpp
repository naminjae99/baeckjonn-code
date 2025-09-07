#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<unordered_set>
#include<string>
#include<string.h>
#include<stack>
#include<sstream>
#include<iomanip>
using namespace std;
using ll = long long;

int T, N;
ll K;
vector<ll> A;


bool can(ll mid) {
    ll used = 0;
    vector<ll> b = A;


    for (int i = 1; i < N; i++) {
        if (b[i] > b[i-1] + mid) {
            used += b[i] - (b[i-1] + mid);
            b[i] = b[i-1] + mid;

            if (used > K) return false;
        }
    }


    for (int i = N-2; i >= 0; i--) {
        if (b[i] > b[i+1] + mid) {
            used += b[i] - (b[i+1] + mid);
            b[i] = b[i+1] + mid;
            if (used > K) return false;
        }
    }

    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        cin >> N >> K;
        A.resize(N);
        for (int i = 0; i < N; i++) cin >> A[i];

        ll st = 0, en = 1e9, ans = en;
        while (st <= en) {
            ll mid = (st + en) / 2;
            if (can(mid)) {
                ans = mid;
                en = mid - 1;
            } else {
                st = mid + 1;
            }
        }
        cout << "#" << tc << " " << ans << "\n";
    }
    return 0;
}
