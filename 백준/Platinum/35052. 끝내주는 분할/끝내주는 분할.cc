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
#include<deque>
#include<unordered_set>
#include<string>
#include<string.h>
#include<stack>
#include<sstream>
#include<iomanip>
#include<deque>
#include<array>
#include<limits.h>
#include<cfloat>
#include<map>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m, k, Q, ret;
bool outbound(int x, int y) {
	return (x <= 0 || x > n || y <= 0 || y > n);
}


int a[300005];
int b[300005];
ll ta[300005];
ll tb[300005];

void upda(int i, ll x) {
	while (i<=n) {
		ta[i] += x;
		i += i & -i;
	}
}
void updb(int i,ll x) {
	while (i <= n) {
		tb[i] += x;
		i += i & -i;
	}
}
ll suma(int i) {
	ll re = 0;
	while (i > 0) {
		re += ta[i];
		i -= i & -i;
	}
	return re;
}
ll sumb(int i) {
	ll re = 0;
	while (i > 0) {
		re += tb[i];
		i -= i & -i;
	}
	return re;
}

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	for (int i = 1; i <= n; i++)
		cin >> b[i];


	int i = 1;
	while (i <= n) {
		ret++;

		vector<int> v;
		int cur = i;
		while (cur <= n) {
			
			ll aa = suma(a[cur]-1);
			ll bb = sumb(b[cur] - 1);



			if (aa == bb) {			upda(a[cur], 1);
			updb( b[cur], 1);
				v.push_back(cur);
				cur++;
			}
			else
				break;
		}
		for (auto c : v) {
			upda(a[c], -1);
			updb(b[c], -1);
		}
		i = cur;

	}
	cout << ret;
}
void solve() {

}
int main() {
	fastio
		input();
	solve();
}