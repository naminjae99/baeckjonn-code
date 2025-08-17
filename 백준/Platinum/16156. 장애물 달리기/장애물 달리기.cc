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
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };



int hs;
struct node {
	int x,y, cost,st;
}heap[1000005];

void push(node x) {
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

int arr[505][505];
int d[505][505];

int cnt[505];

void dik() {
	hs = 0;
	for (int i = 0; i < n; i++)
		fill(d[i], d[i] + m, 1e9);
	for (int i = 0; i < n; i++) {
	
		d[i][m - 1] = arr[i][m - 1];
		push({ i, m-1, d[i][m-1],i });
	}

	while (hs) {
		node cur = pop();
		int x = cur.x;
		int y = cur.y;
		int cost = cur.cost;
		int st = cur.st;
		if (d[x][y] != cost)
			continue;
		if (y == 0) {
			cnt[st]++;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (d[nx][ny] > cost + arr[nx][ny]) {
				d[nx][ny] = cost + arr[nx][ny];
				push({ nx,ny,d[nx][ny],st });
				
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}


	dik();

	
	for (int i = 0; i < n; i++)
		cout << cnt[i] << "\n";
}


