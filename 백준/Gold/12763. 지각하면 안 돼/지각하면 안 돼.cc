#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <string>
#include <string.h>
#include<iomanip>
#include<limits>
#include<cfloat>
using namespace std;
using ll = long long;
using ld = long double;
int t, Q, n, p,m;

int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };


struct f {
	int now, ti, cost;
};
int dis[105][10005];
vector<f> ed[105];

int hs;
f heap[100005];
bool cmp(f a, f b) {
	if (a.cost == b.cost)
		return a.ti < b.ti;
	return a.cost < b.cost;
}
void push(f x) {
	int i = hs++;
	while (i > 0) {
		int par = (i - 1) / 2;
		if (!cmp(x, heap[par]))
			break;
		heap[i] = heap[par];
		i = par;
	}
	heap[i] = x;
}
f pop() {
	f ret = heap[0];
	int i = 0;
	heap[0] = heap[--hs];
	while (1) {
		int le = i * 2 + 1;
		int ri = i * 2 + 2;
		int pr = i;
		if (le < hs&&cmp(heap[le], heap[pr]))
			pr = le;
		if (ri < hs&&cmp(heap[ri], heap[pr]))
			pr = ri;
		if (pr == i)
			break;
		swap(heap[pr], heap[i]);
		i = pr;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	int ti, money;
	cin >> ti >> money;
	cin >> m;
	while (m--) {
		int a, b,c,d;
		cin >> a >> b >>c>> d;
		ed[a].push_back({ b,c,d });
		ed[b].push_back({ a,c,d });
	}
	for (int i = 1; i <= n; i++)
		fill(dis[i], dis[i] + 10004, 1e9);

	dis[1][0] = 0;
	push({ 1,0,0 });
	while (hs > 0) {
		f cur = pop();
		int now = cur.now;
		int tim = cur.ti;
		int cost = cur.cost;
		if (dis[now][tim] != cost)
			continue;
	

		if (now == n) {
			cout << cost;
			return 0;
		}
		for (auto c : ed[now]) {
			int nt = tim + c.ti;
			int nc = cost + c.cost;
			if (nt > ti)
				continue;
			if (nc > money)
				continue;
			if (dis[c.now][nt] > nc) {
				dis[c.now][nt] = nc;
				push({ c.now,nt,nc });
			}
		}
	}
	cout << -1;
}