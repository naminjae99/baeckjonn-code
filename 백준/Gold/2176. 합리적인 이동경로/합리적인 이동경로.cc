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
int n, m, ret, k;


int d[1005];
vector<pair<int,int>> ed[1005];
int vis[1005];
int dp[1005];

int dfs(int cur) {
	if (cur == 2)
		return 1;
	
	if (vis[cur])
		return dp[cur];
	vis[cur] = 1;

	int cnt = 0;

	for (auto c : ed[cur]) {
		if (d[cur] > d[c.first]) {
			cnt += dfs(c.first);
		}
	}

	return dp[cur] = cnt;
}

void input() {
	cin >> n >> m;


	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		ed[x].push_back({y,z});
		ed[y].push_back({x,z});
	}

	fill(d, d + n + 1, 1e9+7);
	priority_queue<pair<int, int>> q;
	q.push({ 0,2 });
	d[2] = 0;

	while (!q.empty()) {
		int now = q.top().second;
		int cost = -q.top().first;
		q.pop();

		if (d[now] != cost)
			continue;

		for (auto c : ed[now]) {
			if (d[c.first] > cost + c.second) {
				d[c.first] = cost + c.second;
				q.push({ -d[c.first],c.first });
			}
		}
	}



	dfs(1);

	cout << dp[1];


}
int main() {
	fastio
		input();
}
