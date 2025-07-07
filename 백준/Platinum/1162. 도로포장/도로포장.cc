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

vector<pair<ll, int>> ed[10005];
int k;

ll d[10005][21];
struct f {
	ll cost;
	int  now, cnt;
	bool operator<(const f& o)const {
		if (cost == o.cost)
			return cnt > o.cnt;
		return cost > o.cost;
	}
};
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL);

	cin >> n >> m >> k;
	while (m--){
		int a, b;
		ll c;
		cin >> a >> b >> c;
		ed[a].push_back({ c,b });
		ed[b].push_back({ c,a });
	}
	priority_queue<f> q;
	q.push({ 0,1,0 });

	for (int j = 1; j <= n; j++) {
		for (int i = 0; i <= k; i++) {
			if (j == 1)
				d[j][i] = 0;
			else
				d[j][i] = 1e18;
		}
	}

	while (!q.empty()) {
		int now = q.top().now;
		ll cost = q.top().cost;
		int cnt = q.top().cnt;
		q.pop();
		if (d[now][cnt] != cost)
			continue;
		
		for (auto c : ed[now]) {
			if (cnt < k) {
				if (d[c.second][cnt+1] >  cost) {
					d[c.second][cnt+1] =  cost;
					q.push({ cost,c.second,cnt+1 });
				}
			}
			if (d[c.second][cnt] > c.first + cost) {
				d[c.second][cnt] = c.first + cost;
				q.push({ d[c.second][cnt],c.second,cnt });
			}
		}
	}
	ll mn = 1e18;
	for (int i = 0; i <= k; i++) {
		mn = min(mn, d[n][i]);

	}
	cout << mn;
}
