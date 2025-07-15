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
using namespace std;
using ll = long long;


int t, n, m;
vector<pair<int, int>>ed[5005];
int s, e;
int d[5005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		ed[a].push_back({ c,b });
		ed[b].push_back({ c,a });
	}
	cin >> s >> e;
	fill(d, d + n + 1, 1e9);
	d[s] = 0;
	priority_queue<pair<int, int>>q;
	q.push({ 0,s });
	while (!q.empty()) {
		int now = q.top().second;
		int cost = -q.top().first;
		q.pop();
		if (d[now] != cost)
			continue;
		if (now == e) {
			cout << cost;
			break;
		}
		for (auto c : ed[now]) {
			if (d[c.second] > cost + c.first) {
				d[c.second] = cost + c.first;
				q.push({ -d[c.second],c.second });
			}
		}
	}

}
