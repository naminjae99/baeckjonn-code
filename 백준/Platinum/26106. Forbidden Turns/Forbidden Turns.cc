#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <string.h>
#include <set>
#include <iomanip>
#include <unordered_set>
#include <map>

using namespace std;

struct State {
	int pre, now;
	int cost;
}heap[100005];
int hs;
void push(State x) {
	int i = hs++;
	while (i) {
		int par = (i - 1) / 2;
		if (heap[par].cost <= x.cost)
			break;
		heap[i] = heap[par];
		i = par;
	}
	heap[i] = x;
}
State pop() {
	State ret = heap[0];
	int i = 0;
	heap[i] = heap[--hs];
	while (1) {
		int le = i * 2 + 1;
		int ri = i * 2 + 2;
		int pr = i;
		if (le < hs&&heap[le].cost < heap[pr].cost)
			pr = le;
		if (ri < hs&&heap[ri].cost < heap[pr].cost)
			pr = ri;
		if (pr == i)
			break;
		swap(heap[pr], heap[i]);
		i = pr;
	}
	return ret;
}
int n, m, k;
int st, en;
vector<pair<int, int>> ed[30005];
unordered_map<int, set<pair<int, int>>> ban;
unordered_map<int, int> dist[30005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n >> k;
	cin >> st >> en;

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		ed[a].push_back({ b,c });
	}

	for (int i = 0; i < k; i++) {
		int a, b, c; cin >> a >> b >> c;
		ban[a].insert({ b,c });
	}


	push({ st, st, 0 });
	dist[st][st] = 0;

	while (hs) {
		State cur = pop();
		int pre = cur.pre, now = cur.now, cost = cur.cost;

		if (dist[now][pre] < cost) continue;  // 더 좋은 경로 존재하면 무시
		if (now == en) {
			cout << cost << "\n";
			return 0;
		}

		for (auto e : ed[now]) {
			int nxt = e.first;
			int w = e.second;
			if (ban.count(pre) && ban[pre].count({ now, nxt })) continue;

			int ncost = cost + w;
			if (!dist[nxt].count(now) || dist[nxt][now] > ncost) {
				dist[nxt][now] = ncost;
				push({ now, nxt, ncost });
			}
		}
	}

	cout << -1 << "\n";
	return 0;
}
