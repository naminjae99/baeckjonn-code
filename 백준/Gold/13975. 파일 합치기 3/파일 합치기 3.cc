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

using namespace std;
using ll = long long;


int t, n, m;


int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);

	cin >> t;
	while (t--) {
		cin >> n;
		priority_queue<ll> qq;
		while (n--) {
			ll x;
			cin >> x;
			qq.push(-x);
		}

		ll sum = 0;
		while (qq.size() != 1) {
			ll a = -qq.top();
			qq.pop();
			ll b = -qq.top();
			qq.pop();
			sum += (a + b);
			qq.push(-(a + b));
			//	cout << a << ", " << b << "\n";
		}
		cout << sum << "\n";
	}
}
