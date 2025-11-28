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
int n, m, ret, t, k, Q, L;


const int lg = 1 << 21;
int par[100005];
vector<int> child[100005];
int sum[100005];
int re[100005];
void dfs(int x, int y) {
	re[x] += y;
	for (auto c : child[x])
		dfs(c, y);
}
void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> par[i];
		child[par[i]].push_back(i);
	}
	while (m--) {
		int x, y;
		cin >> x >> y;
		sum[x] += y;
	}

	for (int i = 1; i <= n; i++) {
		if(sum[i])
			dfs(i, sum[i]);
	}
	for (int i = 1; i <= n; i++) {
		cout << re[i] << " ";
	}
}
void solve() {



}

int main() {
	fastio;
	input();
	solve();
}




