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
#include<cfloat>
#include<array>
using namespace std;
using ll = long long;


int n, m, k, t;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

struct f{
	int now;
	ll cost;
	int dam;
};
vector<f> ed[2005];
ll d[2005][205];
int st, en;
int hs;
f heap[1000005];
bool cmp(f a, f b) {
	if (a.cost != b.cost)
		return a.cost < b.cost;
	return a.dam > b.dam;
}
void push(f x) {
	int i = hs++;
	while (i>0) {
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
	heap[i] = heap[--hs];
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
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> k >> n >> m;
	while (m--) {
		int a, b;
		ll c;
		int h;
		cin >> a >> b >> c >> h;
		ed[a].push_back({ b,c,h });
		ed[b].push_back({ a,c,h });
	}
	cin >> st >> en;
	for (int i = 1; i <= n; i++) {
		fill(d[i],d[i] + k+1, 1e18);
	}
	d[st][k] = 0;
	push({ st,0,k });
	while (hs) {
		f cur = pop();
		int now = cur.now;
		ll cost = cur.cost;
		int dam = cur.dam;
		
		if (d[now][dam] < cost)
			continue;
		if (now == en&&dam>0) {
			cout << cost;
			return 0;
		}
		for (auto c : ed[now]) {
			int newdam = dam - c.dam;
			if (newdam <= 0)
				continue;
			if (d[c.now][newdam] > cost + c.cost) {
				d[c.now][newdam] = cost + c.cost;
				push({ c.now,d[c.now][newdam],newdam });
			}
		}
	}
	cout << -1;
}
