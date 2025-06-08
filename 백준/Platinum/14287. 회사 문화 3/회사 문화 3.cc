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
using namespace std;
using ll = long long;


int n, k, m;
vector<int> arr[100001];
int lazy[400001];
int love[400001];
int cnt;
int s[100001];
int e[100001];
void dfs(int now) {
	s[now] = ++cnt;
	for (auto c : arr[now])
		dfs(c);
	e[now] = cnt;
}
void down(int node, int st, int en) {
	if (lazy[node] != 0) {
		love[node] += lazy[node];
		if (st != en) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void upd(int node, int st, int en, int l,int x) {
	down(node, st, en);
	if (l < st || en < l)
		return;
	if (st==en) {
		love[node] += x;
		return;
	}

	int mid = (st + en) / 2;
	upd(node * 2, st, mid, l, x);
	upd(node * 2 + 1, mid + 1, en, l, x);
	love[node] = love[node * 2] + love[node * 2 + 1];
}
int query(int node, int st, int en, int l,int r) {
	down(node, st, en);
	if (r < st || en < l)
		return 0;
	if (l<=st&&en<=r) {
		return love[node];
	}
	int mid = (st + en) / 2;

	return query(node * 2, st, mid, l,r)+query(node * 2 + 1, mid + 1, en, l,r);
}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL);

	cin >> n >> m;
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x == -1)
			continue;
		arr[x].push_back(i);
	}
	dfs(1);

	int a, b;
	while (m--) {
		cin >> x;
		if (x == 1) {
			cin >> a >> b;
			upd(1, 1, n, s[a], b);
		

		}
		else {
			cin >> a;
			cout<<query(1, 1, n, s[a],e[a])<<"\n";
		}
	}

}