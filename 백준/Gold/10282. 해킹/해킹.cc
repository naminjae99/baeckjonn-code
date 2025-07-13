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

vector<pair<int, int>> ed[10005];
struct f {
	int now, cost;
	bool operator<(const f& o)const {
		return cost > o.cost;
	}
};
priority_queue<f> q;
int d[10005];

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m>>k;

		for (int i = 1; i <= n; i++)
			ed[i].clear();

		while (m--) {
			int a, b, c;
			cin >> a >> b >> c;
			ed[b].push_back({ a,c });
		}
		fill(d, d + n + 1, 1e9);
		d[k] = 0;
		q.push({ k,0});

		int ti;
		int cnt = 0;
		while (!q.empty()) {
			int now = q.top().now;
			int cost = q.top().cost;
		
			q.pop();
			if (d[now] != cost)
				continue;
			cnt++;
			ti = cost;

			for (auto c : ed[now]) {
				if (d[c.first] > cost + c.second) {
					d[c.first] = cost + c.second;
					q.push({ c.first,d[c.first]});
				}
			}
		}
		cout << cnt << " " << ti << "\n";

	}
}
