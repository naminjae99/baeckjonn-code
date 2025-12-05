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
#include<deque>
#include<unordered_set>
#include<string>
#include<string.h>
#include<stack>
#include<sstream>
#include<iomanip>
#include<deque>
#include<array>
#include<limits.h>
#include<cfloat>
#include<map>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;

int dx[8] = {-1,0,1,-1,1,-1,0,1  };
int dy[8] = { 1,1,1,0,0,-1,-1,-1 };
int n, m, ret, k, Q, L;

int arr[505][505];
pair<int, int> st, en;

int hs;
struct f {
	int x, y, cost;
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
	f re = heap[0];
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
	return re;
}
int d[505][505];
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '#')
				arr[i][j] = 1;
			else if (s[j] == 'K')
				st = { i,j };
			else if (s[j] == '*')
				en = { i,j };
			d[i][j] = 1e9;
		}

	}
	d[st.first][st.second] = 0;
	push({ st.first,st.second,0 });

	while (hs) {
		f cur = pop();
		int x = cur.x;
		int y = cur.y;
		int cost = cur.cost;
		
		if (x == en.first&&y == en.second) {
			cout << cost;
			return;
		}
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (arr[nx][ny])
				continue;
			int add = 0;
			if (i >= 3)
				add = 1;
			if (d[nx][ny] > cost+add) {
				d[nx][ny] = cost+add;
				push({ nx,ny,cost+add });
			}
		}
	}

	cout << -1;
}
void solve() {



}

int main() {
	fastio;
	input();
	solve();
}




