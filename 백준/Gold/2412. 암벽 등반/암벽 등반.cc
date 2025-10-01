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
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
int cx, cy;

int n, m, ret, k, t, h, w;

unordered_set<int> arr[200005];
unordered_map<int,int> vis[200005];


void input() {

}
void solve() {
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		arr[y].insert(x);
	}
	

	queue<pair<int, int>> q;
	vis[0][0] = 0;
	q.push({ 0,0 });

	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		//cout << x << "," << y << "\n";
		if (y == t) {
			cout << vis[y][x];
			return;
		}
		if(y>t)
			continue;
		

		for (int i = -2; i <= 2; i++) {
			for (int j = -2; j <= 2; j++) {
				
				int nx = x + i;
				int ny = y + j;
				if (nx < 0 || ny < 0)
					continue;
				if (arr[ny].find(nx) == arr[ny].end())
					continue;
				if (vis[ny].find(nx) != vis[ny].end())
					continue;
				q.push({ nx,ny });
				vis[ny][nx] = vis[y][x] + 1;
				

			}
		}


	}
	cout << -1;

}
int main() {
	fastio;
	input();
	solve();
	//cout << ret;
	return 0;
}

