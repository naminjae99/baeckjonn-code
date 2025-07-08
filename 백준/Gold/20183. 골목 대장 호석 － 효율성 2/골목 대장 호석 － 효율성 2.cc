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


int t, n, m;
int s,e;
ll k;

struct f {
	ll mx, cost;
	int now;
	bool operator<(const f& o)const {
		if (mx == o.mx)
			return cost > o.cost;
		return mx > o.mx;

	}
};

vector< pair<ll, int>> ed[100005];
ll d[100005];
bool flag;

void dik(int x) {
	fill(d, d + n+1, 1e18);
	priority_queue<f>q;
	q.push({ 0,0,x });
	d[x] = 0;
	while (!q.empty()) {
		int now = q.top().now;
		ll cost = q.top().cost;
		ll mx = q.top().mx;
		q.pop();
		if (d[now] != cost)
			continue;
		if (now == e && cost <= k) {
			cout << mx;
			flag = 1;
			return;
		}
		

		for (auto c : ed[now]) {
			if (c.first+cost<=k&&d[c.second] > c.first + cost) {
				d[c.second] = c.first + cost;
				q.push({ max(mx,c.first),d[c.second],c.second });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL),  cout.tie(0);

	cin >> n>>m>>s>>e>>k;
	while (m--) {
		int a, b;
		ll  c;
		cin >> a >> b >> c;
		ed[a].push_back({ c,b });
		ed[b].push_back({ c,a });
	}
	dik(s);
	if (flag == 0)
		cout << -1;
}
