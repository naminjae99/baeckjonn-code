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


int n,m,k;
int vis[10005];
vector<pair<int,int>> ed[10005];
int s, e;
struct f {
	int cost,now;
	bool operator<(const f& o)const {
		if (cost == o.cost)
			return now > o.now;
		return cost > o.cost;
	}
};
priority_queue<f> q;
int d[10005];
int par[10005];
int sum;
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	
	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b;
		ed[a].push_back({ 1,b });
		ed[b].push_back({ 1,a });
	}
	cin >> s >> e;

	fill(d, d + n + 1, 1e9);
	q.push({ 0,s });
	d[s] = 0;

	while (!q.empty()) {
		int cost = q.top().cost;
		int now = q.top().now;
		q.pop();
		if (d[now] != cost)
			continue;
	//	cout << cost << ", " << now << "확인중\n";

		for (auto c : ed[now]) {
			if (d[c.second] > cost + c.first) {
				d[c.second] = cost + c.first;
				q.push({ d[c.second],c.second });
				par[c.second] = now;
			//	cout << d[c.second] << " ," << c.second << "추가\n";
			}
			else if (d[c.second] == cost + c.first) {
				//par[c.se]->c.s  // now c.s
				//이미 있던 전 경로가 now보다 큰값이면
				if (c.second > now) {
					//q.push({ d[c.second],c.second });
					par[c.second] = now;
				//	cout << d[c.second] << " ," << c.second << "추가는 안함\n";
				}
			}
			
		}
	//	cout << "\n\n\n";
	}
	int cur = par[e];
	while (1) {
		vis[cur] = 1;
		cur = par[cur];
		if (cur == s||cur==0)
			break;
	}



	sum += d[e];

	q = {};
	fill(d, d + n + 1, 1e9);
	q.push({ 0,e });
	d[e] = 0;

	while (!q.empty()) {
		int cost = q.top().cost;
		int now = q.top().now;
		q.pop();
		if (d[now] != cost)
			continue;
	
		for (auto c : ed[now]) {
			if (!vis[c.second]&&d[c.second] > cost + c.first) {
				d[c.second] = cost + c.first;
				q.push({ d[c.second],c.second });
			}
			
		}
	}
	cout << sum + d[s];
}
