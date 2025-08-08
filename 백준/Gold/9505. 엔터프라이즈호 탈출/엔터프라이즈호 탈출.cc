#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<string.h>
#include<set>
#include<unordered_set>
using namespace std;

int t, k, n, m;
int arr[1005][1005];
long long val[26];
pair<int, int> st;
long long d[1005][1005];

int hs;
struct node {
	int x, y;
	long long cost;
}heap[1000005];

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
		swap(heap[pr], heap[i]);
		i = pr;
	}
	return ret;
}
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int main(){
     cin.tie(NULL); ios_base::sync_with_stdio(false);
	cin >> t;
	while (t--) {
		cin >> k >> m >> n;
		while (k--) {
			char a;
			long long b;
			cin >> a >> b;
			val[a - 'A'+1] = b;
		}
		memset(arr, 0, sizeof(arr));

		string s;
		for (int i = 1; i <= n; i++) {
			cin >> s;
			for (int j = 1; j <= m; j++) {
				arr[i][j] = s[j - 1]-'A'+1;
				if (s[j - 1] == 'E') 
					st = { i,j };
			}
			fill(d[i], d[i] + m + 2, 1e18);
		}
		
		fill(d[0], d[0] + m + 2, 1e18);
		fill(d[n+1], d[n+1] +m + 2, 1e18);
		hs = 0;
		d[st.first][st.second] = 0;
		push({ st.first,st.second,0 });
		while (hs) {
			node cur = pop();
			int x = cur.x;
			int y = cur.y;
			long long cost = cur.cost;

			if (d[x][y] != cost)
				continue;
			if (x == 0 || x == n + 1 || y == 0 || y == m + 1) {
				cout << cost<<"\n";
				break;
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (d[nx][ny] > cost + val[arr[nx][ny]]) {
					d[nx][ny] = cost + val[arr[nx][ny]];
					push({ nx,ny,d[nx][ny] });
				}
			}
		}


	}
}