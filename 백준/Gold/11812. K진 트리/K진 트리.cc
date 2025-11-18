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

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int  m, ret, t, Q, L;
ll k, n;
unordered_map<ll, int> d;


// x-k+2/k 는 부모
ll par(ll x) {
	return (x + k - 2) / k;
}
void input() {
	cin >> n >> k >> Q;
	ll x, y;

	while (Q--) {
		cin >> x >> y;
		if (k == 1) {
			cout << abs(y-x) << "\n";
			continue;
		}

		int dis = 0;
\
		while (x != y) {
			if (x < y)
				swap(x, y);
			x = par(x);
			dis++;
		}
		
		cout << dis << "\n";
	}
}
void solve() {


}

int main() {
	fastio;
	input();
	solve();
}









