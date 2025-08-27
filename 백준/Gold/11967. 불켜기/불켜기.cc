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
#include<iomanip>
#include<unordered_set>

using namespace std;
int n, t, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int arr[105][105];
vector<pair<int, int>> info[105][105];

void init() {
	
}
void input() {
	cin >> n >> m;
	while (m--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		info[a][b].push_back({ c,d });
	}
	
}
bool vis[105][105];

queue <pair<int, int>> q;
int re = 0;
bool lgt[105][105];

void bfs() {
	q.push({ 1,1 });
	vis[1][1] = 1;
	lgt[1][1] = 1;
	re = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		bool flag = 0;
		for (auto c : info[x][y]) {
			if (lgt[c.first][c.second] == 0) {
				lgt[c.first][c.second] = 1;
				re++;
				flag = 1;
			}
		}

		if (flag) {
			q = {};
			memset(vis, 0, sizeof(vis));
			q.push({ 1,1 });
			vis[1][1] = 1;
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || nx>n || ny<1 || ny>n)
				continue;
			if (vis[nx][ny])
				continue;
			if (lgt[nx][ny]) {
				q.push({ nx,ny });
				vis[nx][ny] = 1;
			}
		}
	}

	
	cout << re;
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	
	input();
	bfs();

}