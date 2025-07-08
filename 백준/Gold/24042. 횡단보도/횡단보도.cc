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

using namespace std;
using ll = long long;


int t, n;
ll m;
vector<pair<ll, int>> ed[100005];
ll d[100005];
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);

	cin >> n >> m;
	for (int i =0; i <m; i++) {
		int a, b;
		cin >> a >> b;
		ed[a].push_back({i,b });
		ed[b].push_back({ i,a });
	}
	priority_queue<pair<ll, int>> q;
	fill(d, d + n + 1, 1e18);
	q.push({ 0,1 });
	d[1] = 0;

	while (!q.empty()) {
		int now = q.top().second;
		ll cost = -q.top().first;
		q.pop();

		//cout << now << ", " << cost << "확인 \n";

		if (d[now] < cost)
			continue;

		if (now == n) {
			cout << cost;
			break;
		}
		for (auto c : ed[now]) {
			ll offset = (ll)c.first;
			int to = c.second;

			ll wait = ((cost - offset + m - 1) / m) * m + offset;
			ll arrive = wait + 1;

			if (d[to] > arrive) {
				d[to] = arrive;
				q.push({ -arrive, to });
			}
		}
	}

}
