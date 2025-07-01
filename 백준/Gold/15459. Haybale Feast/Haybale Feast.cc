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
using namespace std;
using ll = long long;

ll f[100005];  // flavor
ll s[100005];  // spiciness

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> f[i] >> s[i];
    }

    ll sum = 0;
    int l = 0;
    ll answer = 1e18;

    multiset<ll> spicy;

    for (int r = 0; r < n; r++) {
        sum += f[r];
        spicy.insert(s[r]);

        // sum이 M 이상일 때마다 왼쪽 포인터를 이동하며 최소 매움값을 갱신
        while (sum >= m) {
            answer = min(answer, *spicy.rbegin());  // 최대 spiciness
            sum -= f[l];
            spicy.erase(spicy.find(s[l]));
            l++;
        }
    }

    cout << answer << '\n';
    return 0;
}
