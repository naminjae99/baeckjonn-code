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

struct f {
	int now;
    ll cnt;
	bool operator<(const f& o)const {
		return cnt > o.cnt;
	}
};
priority_queue<f> q;


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

bool vis[100005];
vector<pair<ll, int>> ed[100005];
ll d[100005];
bool bound(int x, int y) {
	return (x < 0 || x >= n || y < 0 || y >= m);
}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> vis[i];
	while (m--) {
		int a, b;
        ll c;
		cin >> a >> b >> c;
		ed[a].push_back({ c,b });
		ed[b].push_back({ c,a });
	}
	fill(d, d + n, 1e18);
	d[0] = 0;
	q.push({ 0,0 });

	while (!q.empty()){
		int now = q.top().now;
		ll cnt = q.top().cnt;
		q.pop();
		if (d[now] != cnt)
			continue;
		for (auto c : ed[now]) {
			if (d[c.second] > cnt + c.first&&vis[c.second] == 0) {
				d[c.second] = cnt + c.first;
				q.push({ c.second,d[c.second] });
			}
			if (c.second == n - 1) {
				if (d[c.second] > cnt + c.first) {
					d[c.second] = cnt + c.first;
					q.push({ c.second,d[c.second] });
				}
			}
		}
	}
	if (d[n - 1] == 1e18)
		cout << -1;
	else
		cout << d[n - 1];
}
