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

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

int n, m, ret, k, t, h;


pair<int, int> xy[2005];
vector<pair<int,int>> ed[2005];
int par[2005];

struct f {
	int x, y, cost;
	bool operator<(const f& o)const {
		return cost < o.cost;
	}
};
vector<f>v;

int find(int x) {
	if (par[x] < 0)
		return x;
	return par[x] = find(par[x]);
}
void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	par[b] = a;
}
void input() {
	cin >> n >> m;
	memset(par, -1, sizeof(par));
	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		xy[i] = { x,y };
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i+1; j <= n; j++) {
			int dis = (xy[i].first - xy[j].first)*(xy[i].first - xy[j].first)
				+ (xy[i].second - xy[j].second)*(xy[i].second - xy[j].second);
			if (dis >= m) {
				v.push_back({ i,j,dis });
			}
		}
	}
	sort(v.begin(), v.end());

	int cnt = 0;
	for (auto c : v) {
		int x = c.x;
		int y = c.y;
		if (find(x) == find(y))
			continue;
		uni(x, y);
		cnt++;
		ret += c.cost;
if (cnt == n - 1)
			return;
	}
	ret = -1;

}

void solve() {

}
int main() {
	fastio;
	input();
	solve();
	cout << ret;
	return 0;
}

