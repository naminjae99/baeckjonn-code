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
int t,Q, n, m, p;

int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };


struct Node {
	int x, y, cost,cnt;
};
bool cmp(Node a,Node b){
	if (a.cost != b.cost)
		return a.cost < b.cost;
	return a.cnt < b.cnt;
}

int hs;
Node heap[100005];

void push(int x,int y,int cost,int cnt) {
	int i = hs++;
	while (i > 0) {
		int par = (i - 1) / 2;
		if (heap[par].cost == cost) {
			if (heap[par].cnt <= cnt)
				break;
		}
		else if(heap[par].cost<cost)
			break;

		heap[i] = heap[par];
		i = par;
	}
	heap[i] = { x,y,cost,cnt };
}
Node pop() {
	Node ret = heap[0];
	int i = 0;
	heap[0] = heap[--hs];
	while (1) {
		int le = i * 2 + 1;
		int ri = i * 2 + 2;
		int pr = i;
		if (le < hs&& cmp(heap[le],heap[pr]))
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
int arr[101][101];
int d[101][101][3];
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> t;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			d[i][j][0]= d[i][j][1]= d[i][j][2]=1e9;
		}
	}
	d[0][0][0] = 0;
	push(0, 0, 0, 0);
	while (hs > 0) {
		Node now = pop();
		int x = now.x;
		int y = now.y;
		int cost = now.cost;
		int cnt = now.cnt;
		//cout << x <<", "<< y << ", " << cost << ", " << cnt << "\n";
	
		if (d[x][y][cnt] != cost)
			continue;
		if (x == n - 1 && y == n - 1) {
			cout << cost;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (cnt == 2) {
				if (d[nx][ny][0] >arr[nx][ny]+ cost + t) {
					d[nx][ny][0] = arr[nx][ny] + cost + t;
					push(nx, ny, d[nx][ny][0], 0);
				}
			}
			else {
				if (d[nx][ny][cnt+1] >   cost + t) {
					d[nx][ny][cnt+1] =  cost + t;
					push(nx, ny, d[nx][ny][cnt+1], cnt+1);
				}
			}
			
		}
	}
}