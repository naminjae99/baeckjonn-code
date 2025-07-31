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

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int n, m, Q, p, q;

int hs;
struct node {
	int now;
	ll cost;
};
node heap[1000005];
void push(node x) {
	int i = hs++;
	while (i > 0) {
		int par = (i - 1) / 2;
		if (heap[par].cost <= x.cost)
			break;
		heap[i] = heap[par];
		i = par;
	}
	heap[i] = x;
}
node pop() {
	node ret = heap[0];
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
		swap(heap[i], heap[pr]);
		i = pr;
	}
	return ret;
}

int ord[11];
vector<pair<ll, int>> ed[10005];
ll d[10005];
ll dis[10005];

ll dik(int st, int en) {
	hs = 0;
	fill(d, d + n + 1, 1e18);
	d[st] = 0;
	push({ st,0 });

	while (hs > 0) {
		node cur = pop();
		int now = cur.now;
		ll cost = cur.cost;
		if (d[now] != cost)
			continue;
		if (now == en)
			return cost;
		for (auto c : ed[now]) {
			if (d[c.second] > cost + c.first) {
				d[c.second] = cost + c.first;
				push({ c.second,d[c.second] });
			}
		}
	}
	return 1e18;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	while (m--) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		ed[a].push_back({ c,b });
		ed[b].push_back({ c,a });
	}
	for (int i = 0; i < 10; i++)
		cin >> ord[i];



	int id = 1e9;


	int st;
	cin >> st;
	fill(dis, dis + n + 1, 1e18);
	dis[st] = 0;
	push({ st,0 });

	while (hs > 0) {
		node cur = pop();
		int now = cur.now;
		ll cost = cur.cost;
		if (dis[now] != cost)
			continue;

		for (auto c : ed[now]) {
			if (dis[c.second] > cost + c.first) {
				dis[c.second] = cost + c.first;
				push({ c.second,dis[c.second] });
			}
		}
	}



	ll sum = 0;
	int cur = ord[0];

	for (int i = 0; i < 10; i++) {
		ll tmp = dik(cur, ord[i]);
		if (tmp == 1e18)
			continue;
		sum += tmp;
		if (dis[ord[i]] <= sum)
			id = min(id, ord[i]);
		cur = ord[i];
	}
	
	
	if (id == 1e9)
		cout << -1;
	else
		cout << id;
}