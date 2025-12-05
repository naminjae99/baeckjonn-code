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

int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { 1,1,1,0,0,-1,-1,-1 };
int n, m, ret, k, Q, L;
int c;

int tree[100005];
int lazy[100005];

void down(int node, int s, int e) {
	if (lazy[node]) {
		tree[node] += lazy[node];
		if (s != e) {
			lazy[node << 1] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void upd(int node, int s, int e, int l, int r, int x) {
	down(node, s, e);
	if (e < l || r < s)
		return;
	if (l <= s && e <= r) {
		lazy[node] = x;
		down(node, s, e);
		return;
	}
	int mid = (s + e) >> 1;
	upd(node << 1, s, mid, l, r, x);
	upd((node << 1) | 1, mid + 1, e, l, r, x);
	tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
}
int query(int node, int s, int e, int l, int r) {
	down(node, s, e);
	if (e < l || r < s)
		return 0;
	if (l <= s && e <= r)
		return tree[node];
	int mid = (s + e) >> 1;
	int a = query(node << 1, s, mid, l, r);
	int b = query((node << 1) | 1, mid + 1, e, l, r);
	return max(a, b);
}


vector<array<int,3>> v;
void input() {
	cin >> m >> n >> c;
	for (int i = 0; i < m; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		v.push_back({y,x,z });
	}
	sort(v.begin(), v.end());



	for (int i = 0; i < m; i++) {
		int x = v[i][1];
		int y = v[i][0];
		int z = v[i][2];

		int mx = query(1, 1, n, x, y - 1);
		//구간의 최대값

		int add = min(c - mx, z);
		if (add) {
			upd(1, 1, n, x, y - 1, add);
			ret += add;
		}
	
	}
	cout << ret;

}
void solve() {



}

int main() {
	fastio;
	input();
	solve();
}




