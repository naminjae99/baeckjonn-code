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

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, ret, t, k, Q;

int tree[5000005];
void upd(int val, int x) {
	int i = m + val;

	while (i) {
		tree[i] += x;
		i /= 2;
	}

}
int query(int x) {
	int i = 1;
	int le;
	while (i <= m) {
		le = tree[i * 2];
		if (le >= x)
			i *= 2;
		else {
			i=i*2 + 1;
			x -= le;
		}
	}
	return i - m;
}
void input() {
	cin >> n;
	m = 1;
	while (1) {
		if (m < 2000000)
			m *= 2;
		else
			break;
	}

	while (n--) {
		int cmd, x;
		cin >> cmd >> x;
		if (cmd == 1) {
			upd(x, 1);
		}
		else {
			int re=query(x);
			cout << re<<"\n";
			upd(re, -1);
		}
	}
}
void solve() {

}

int main() {
	fastio;
	input();
}





