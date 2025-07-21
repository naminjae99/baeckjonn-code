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
#include<map>
#include<iomanip>
#include<cfloat>
#include<array>
using namespace std;
using ll = long long;


int n, m, k, t;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


struct f {
	int now,cost;
	bool operator<(const f& o)const {
		return cost > o.cost;
	}
};
vector<pair<int, int>> ed[11];
int d[10005];
//st에서 i로 x원써서 갈때 사용한 max요금

int st,en,total;


int l, r;
bool cango(int x) {
	fill(d, d + n + 1, 1e9);
	d[st] = 0;
	priority_queue<f>q;
	q.push({ st,0 });

	while (!q.empty()) {
		int now = q.top().now;
		int cost = q.top().cost;
		q.pop();
		if (d[now]!=cost)
			continue;
		if (now == en)
			return 1;
		for (auto c : ed[now]) {
			if (c.first > x)
				continue;
			if (d[c.second] > cost+c.first&&cost+c.first<=total) {
				d[c.second]=c.first+cost;
				q.push({ c.second,d[c.second]});
			}
		}
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m >> st >> en >> total;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		r = max(r, c);
		ed[a].push_back({ c,b });
		ed[b].push_back({ c,a });
	}
	int mid;
	int re = -1;
	while (l <= r) {
		mid = (l + r) / 2;
		if (cango(mid)) {
			re = mid;
			r = mid - 1;
		}
		else
			l = mid + 1;
	}
	cout << re;

	
}
