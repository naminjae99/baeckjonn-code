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
#include<deque>
#include<array>
#include<limits.h>
#include<cfloat>
using namespace std;
using ll = long long;

int dx[4] = { 0,1,0,-1};
int dy[4] = { -1,0,1,0 };


int n, m, t,k,ret;

int par[300005];
ll sub[300005];
vector<int> ed[300005];

int dfs(int x) {
	sub[x] = 1;
	for (auto c : ed[x]) {
		if (c == par[x])
			continue;
		par[c] = x;
		sub[x]+=dfs(c);
	}
	return sub[x];
}
ll re = 0;
ll total = 0;
void input() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		ed[a].push_back(b);
		ed[b].push_back(a);
	}
	dfs(1);

	for (int i = 1; i <= n; i++) {
		int p = par[i];
		if (p == 0)
			continue;
		ll as = sub[i];
	
		re += as * (as - 1) / 2 + as * (n - as);
	}
	cout << re;
}
void solve() {
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	input();
	solve();
	//cout << ret;
	return 0;
}