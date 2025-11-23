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

vector<pair<int, int>> ed[40006];
pair<int,int> par[40005][20];
int dep[40005];

void dfs(int x, int p) {
	dep[x] = dep[p] + 1;
	


	for (auto c : ed[x]) {
		if (c.first == p)
			continue;
		par[c.first][0] = {x,c.second};
		dfs(c.first,x);
	}
}
void input() {
	cin >> n;
	int x, y, z;
	for (int i = 0; i < n - 1; i++) {
		cin >> x >> y >> z;
		ed[x].push_back({ y,z });
		ed[y].push_back({ x,z });
	}
	
	dfs(1, 0);

	for(int j=1;j<=18;j++){
		for (int i = 1; i <= n; i++) {
			if (par[i][j - 1].first) {
				par[i][j] = { par[par[i][j - 1].first][j - 1].first,
					par[i][j-1].second+ par[par[i][j - 1].first][j - 1].second };
			}
		}
	}


	


	cin >> m;
	while (m--) {
		cin >> x >> y;
		if (dep[x] < dep[y])
			swap(x, y);
		int dif = dep[x] - dep[y];
		int dis = 0;
		for (int i = 18; i >= 0; i--) {
			if (dif&(1 << i)) {
				dis += par[x][i].second;
				x = par[x][i].first;
			}
		}

		if (x == y) {
			cout << dis << "\n";
			continue;
		}

		for (int i = 18; i >= 0; i--) {
			if (par[x][i].first != par[y][i].first) {
				dis += par[x][i].second+par[y][i].second;
				x = par[x][i].first;
				y = par[y][i].first;
			}
		}

		cout << dis + par[x][0].second + par[y][0].second << "\n";

	}

}
void solve() {



}

int main() {
	fastio;
	input();
	solve();
}











