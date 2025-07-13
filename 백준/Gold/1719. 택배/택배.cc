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
using namespace std;
using ll = long long;

int n, m, k, t;

vector<pair<int, int>> ed[205];
struct f {
	int now, cost;
	bool operator<(const f& o)const {
		return cost > o.cost;
	}
};
priority_queue<f> q;
int d[205][205];
int par[205][205];

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);

	cin >> n >> m;


	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		ed[a].push_back({ b,c });
		ed[b].push_back({ a,c });
	}
	for (int i = 1; i <= n; i++) {
		fill(d[i], d[i] + n + 1, 1e9);
		d[i][i] = 0;
		q.push({ i,0 });
		par[i][i] = i;

		while (!q.empty()) {
			int now = q.top().now;
			int cost = q.top().cost;

			q.pop();
			if (d[i][now] != cost)
				continue;
		

			for (auto c : ed[now]) {
				if (d[i][c.first] > cost + c.second) {
					d[i][c.first] = cost + c.second;
					q.push({ c.first,d[i][c.first] });
					par[i][c.first] = now;
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				cout << '-' << " ";
			else {
				int cur = j;
				while (par[i][cur] != i) {
					cur = par[i][cur];
				}
				
				cout << cur << " ";
			}
		}
		cout << "\n";
	}
}
