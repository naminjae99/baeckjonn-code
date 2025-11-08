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
int dy[4] = { 0,0,-1,1 };
int n, m, ret, k, Q;


int dp[10005][2];
int arr[10005];
vector<int> ed[10005];
int vis[10005];

void dfs(int x) {
	vis[x] = 1;
	dp[x][0] = 0;
	dp[x][1] = arr[x];

	for (auto c : ed[x]) {
		if (vis[c])
			continue;
		dfs(c);
		dp[x][0] += max(dp[c][1],dp[c][0]);
		dp[x][1] += dp[c][0];
	}

}
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	dfs(1);
	cout << max(dp[1][1], dp[1][0]);
}
void solve() {
	
}


int main() {
	fastio;
	input();
	solve();
	return 0;
}







