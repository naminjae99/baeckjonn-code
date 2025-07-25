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
int Q, n, m, p;

int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };

pair < ld,ld > bal[1005];
ld dis[1005][1005];

ld d[1005];

struct Node {
	int now;
	ld cost;
};
int hs;
Node heap[100005];

void push(int now, ld cost) {
	int i = hs++;
	while (i > 0) {
		int par = (i - 1) / 2;
		if (heap[par].cost <= cost)
			break;
		heap[i] = heap[par];
		i = par;
	}
	heap[i] = { now,cost };
}
Node pop() {
	Node ret = heap[0];
	int i = 0;
	heap[i] = heap[--hs];

	while (1) {
		int l = i * 2 + 1;
		int r = i * 2 + 2;
		int pr = i;
		if (l < hs&&heap[l].cost < heap[pr].cost)
			pr = l;
		if (r < hs&&heap[r].cost < heap[pr].cost)
			pr = r;
		if (pr == i)
			break;
		swap(heap[pr], heap[i]);
		i = pr;
	}
	return ret;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	ld k;
	cin >> n >> m;
	cin >> k;

	for (int i = 1; i <= n; i++) {
		ld x, y;
		cin >> x >> y;
		bal[i] = { x,y };
		d[i] = LDBL_MAX;
	}
	

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {

			ld x = (bal[i].first - bal[j].first);
			ld y = (bal[i].second - bal[j].second);
			ld dist = sqrt(x*x + y * y);
			if (dist <= k) {
				dis[i][j]=dis[j][i] = dist;
			}
			else {
				dis[i][j] = dis[j][i] = LDBL_MAX;
			}
			

		}
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		dis[x][y] = dis[y][x] = 0;
	}

	hs = 0;
	push(1, 0);
	d[1] = 0;
	while (hs > 0) {
		Node now = pop();
		if (d[now.now] != now.cost)
			continue;
		//cout << now.now << "발전소 까지 추가 전선 :" << now.cost << "\n";
		if (now.now == n) {
			cout << (long long)(floor(now.cost * 1000));
			break;
		}
		for (int i = 1; i <= n; i++) {
			if (dis[now.now][i] == LDBL_MAX)
				continue;
			if (d[i] > now.cost + dis[now.now][i]) {
				d[i] = now.cost + dis[now.now][i];
				push(i, d[i]);
			}
			
		}
	}


}