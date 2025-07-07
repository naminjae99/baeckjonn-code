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

vector<pair<int, int>> ed[505];

int s, e;
int d[505];
vector<int> par[505];
bool vis[505][505];
bool qv[505];

struct f {
	int cost, now, pre;
	bool operator<(const f& o)const {
		return cost > o.cost;
	}
};

void fi2() {

	fill(d, d + n, 1e9);

	priority_queue<pair<int, int>>q;
	q.push({ 0,s });
	d[s] = 0;

	while (!q.empty()) {
		int now = q.top().second;
		int cost = -q.top().first;
		q.pop();
		if (d[now] != cost)
			continue;
		//cout << now << " ," << cost << "확인\n";
		if (now == e)
			return;
		for (auto c : ed[now]) {
			if (vis[now][c.second])
				continue;
			if (d[c.second] > cost + c.first) {
				d[c.second] = cost + c.first;
				q.push({ -d[c.second],c.second });
				//	cout << c.second << " ," << d[c.second] << "추가\n";
			}
		}
		//cout << "\n\n";
	}


}
void del(int no) {

	for (auto c : par[no]) {
		if (vis[c][no] == 0) {
			vis[c][no] = 1;
			if (c != s)
				del(c);
		}
	}

}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL);

	while (1) {
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		cin >> s >> e;


		bool flag = 0;
		for (int i = 0; i < n; i++) {
			ed[i].clear();
			par[i].clear();
		}
		memset(vis, 0, sizeof(vis));
		memset(qv, 0, sizeof(qv));

		while (m--) {
			int a, b, c;
			cin >> a >> b >> c;
			ed[a].push_back({ c,b });
		}

		fill(d, d + n, 1e9);

		priority_queue<pair<int,int>>q;
		q.push({ 0,s });
		d[s] = 0;

		while (!q.empty()) {
			int now = q.top().second;
			int cost = -q.top().first;
	
			q.pop();
			
			if (d[now] != cost)
				continue;
			
			if (now == e)
				flag = 1;
			
			for (auto c : ed[now]) {
				if (d[c.second] > cost + c.first) {
					d[c.second] = cost + c.first;
					q.push({ -d[c.second],c.second });
					par[c.second].clear();
					par[c.second].push_back(now);
				}
				else if (d[c.second] == cost + c.first)
					par[c.second].push_back(now);
				
			}

		}


		if (flag == 0) {
			cout << -1 << "\n";
			continue;
		}
		del(e);
		
		//거의 최단경로
		fi2();
		if (d[e] == 1e9)
			cout << -1;
		else
			cout << d[e];
		cout << "\n";
	}
}
