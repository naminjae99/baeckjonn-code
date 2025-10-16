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
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, ret, k, t, Q;


vector<int> ed[100005];
int par[100005];
int root;
bool vis[100005];
int cnt[100005];

int dfs(int x) {
	vis[x] = 1;
	int re = 1;

	for (auto c : ed[x]) {
		if (vis[c])
			continue;
		vis[c] = 1;
		par[c] = x;
		re+=dfs(c);
	}
	cnt[x] = re;
	return re;
}
void input() {
	cin >> n >> root>>m;
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	dfs(root);

	while (m--) {
		int cmd;
		cin >> cmd;
		cout << cnt[cmd] << "\n";
	}
}
void solve() {
	
}
int main() {
	fastio;
	input();
	solve();

}




