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
#include<map>
#include<iomanip>
#include<array>
using namespace std;
using ll = long long;


int n, m, k, t;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector<int> ch[100001];
int st[100001];
int en[100001];
int used;
void dfs(int now) {
	st[now]=++used;
	for (auto c : ch[now]) {
		dfs(c);
	}
	en[now] = used;
}
int tree[400004];
int lazy[400004];
void down(int no, int s, int e) {
	if (lazy[no]) {
		tree[no] += lazy[no];
		if (s != e) {
			lazy[no << 1] += lazy[no];
			lazy[no << 1 | 1] += lazy[no];
		}
		lazy[no] = 0;
	}
}
int upd(int no, int s, int e, int l, int r, int x) {
	down(no, s, e);
	if (e < l || r < s)
		return 0;
	if (l <= s && e <= r) {
		lazy[no] += x;
		down(no, s, e);
		return tree[no];
	}
	int mid = (s + e) >> 1;
	int a = upd(no << 1, s, mid, l, r, x);
	int b = upd(no << 1 | 1, mid + 1, e, l, r, x);
	return tree[no] = a + b;
}
int query(int no, int s, int e, int idx) {
	down(no, s, e);
	if (e < idx || idx < s)
		return 0;
	if (s==e) {
		return tree[no];
	}
	int mid = (s + e) >> 1;
	int a = query(no << 1, s, mid, idx);
	int b = query(no << 1 | 1, mid + 1, e, idx);
	return a + b;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n >> m;
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (i == 1)
			continue;
		ch[x].push_back(i);
	}
	dfs(1);
	int a, b;
	while (m--) {
		cin >> x;
		if (x == 1) {
			cin >> a >> b;
	
			upd(1, 1, n, st[a], en[a], b);
		}
		else {
			cin >> a;
			cout<<query(1, 1, n, st[a])<<"\n";
		}
	}

}
