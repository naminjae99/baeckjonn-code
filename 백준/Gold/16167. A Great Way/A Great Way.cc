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
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m, k, t,Q, ret;
bool outbound(int x, int y) {
	return (x < 0 || x >= n || y < 0 || y >= m);
}

int arr[1005][1005];
int v, b;
int vis[1005][1005];


struct  f{
	int now, cost,cnt;
	bool operator<(const f& o)const {
		return cost > o.cost;
	}
};



vector<pair<int, int>> ed[105];
//비용 시간
pair<int,int> d[105];

void input() {
	cin >> n >> m;
	while (m--) {
		int s, e, c, plus, tm;
		cin >> s >> e >> c >> plus >> tm;
		if (tm > 10)
			ed[s].push_back({ e,c + (tm - 10)*plus });
		else
			ed[s].push_back({ e,c});
	}
	for (int i = 1; i <= n; i++)
		d[i] = { 1e9,1e9 };

	d[1] = {0,1};
	priority_queue<f>q;
	q.push({ 1,0,1 });

	while (!q.empty()) {
		int now = q.top().now;
		int cost = q.top().cost;
		int cnt = q.top().cnt;
		q.pop();

		if (d[now] != make_pair(cost,cnt))
			continue;

		if (now == n) {
			cout << cost<<" "<<cnt;
			return;
		}

		for (auto c : ed[now]) {
			int nxt = c.first;
			int nc = c.second;
			if (d[nxt] > make_pair(cost + nc,cnt+1)) {
				d[nxt] = { cost + nc,cnt + 1 };
				q.push({ nxt,d[nxt].first,cnt+1 });
			}

			
		}
	}

	cout << "It is not a great way.";
}
void solve() {

}
int main() {
	fastio
		input();
	solve();
}