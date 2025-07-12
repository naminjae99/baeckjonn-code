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

int st;
vector<int> ed[300005];
int d[300005];
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n>>m>>k>>st;
	while (m--) {
		int a, b;
		cin >> a >> b;
		ed[a].push_back(b);
	}

	fill(d, d + n + 1, 1e9);
	priority_queue<pair<int, int>> q;
	q.push({ 0,st });
	d[st] = 0;
	while (!q.empty()) {
		int now = q.top().second;
		int cost = -q.top().first;
		q.pop();
		if (d[now] != cost)
			continue;
		for (auto c : ed[now]) {
			if (d[c] > cost + 1) {
				d[c] = cost + 1;
				q.push({ -d[c],c });
			}
		}
	}
	bool flag = 0;
	for (int i = 0; i <= n; i++) {
		if (d[i] == k) {
			cout << i << "\n";
			flag = 1;
		}
	}
	if (!flag)
		cout << -1;
}
