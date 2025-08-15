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
#include<cfloat>
#include<sstream>
#include<numeric>
#include <limits>
using namespace std;
using ll = long long;



int n, m, k;
vector<pair<int, ll>> ed[100005];

int hs;
struct f{
	int now;
	ll cost;
}heap[1000005];
void push(f x) {
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
f pop() {
	f ret = heap[0];
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

bool vis[100005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> k;
	ll total = 0;
	while (m--) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		ed[a].push_back({ b,c });
		ed[b].push_back({ a,c });
		total += c;


	}

	vector <pair<ll, int>> d(n + 1);
	for (int i = 1; i <= n; i++)
		d[i] = { 1e18,i };

	d[1].first = 0;
	push({ 1,0});
	while (hs) {
		f cur = pop();
		ll cost = cur.cost;
		int now = cur.now;

		if (d[now].first != cost)
			continue;
		for (auto c : ed[now]) {
			if (d[c.first].first > cost + c.second) {
				d[c.first].first = cost + c.second;
				push({ c.first,d[c.first].first});
			}
		}
	}

	sort(d.begin() + 1, d.end());
	vis[1] = 1;
	ll mn = total;

	for (int i = 2; i <= n; i++) {
		ll x = d[i].first;
		int cur = d[i].second;
		vis[cur] = 1;
		
		//cout << cur << "," << x << "\n";
		for (auto c : ed[cur]) {
			if (vis[c.first])
				total -= c.second;
		}
		mn = min(mn, k*x + total);
	}
	cout << mn;
}


