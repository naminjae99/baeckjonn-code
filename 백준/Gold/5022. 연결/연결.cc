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

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, ret, k, t, Q;

int arr[105][105];
int vis[105][105];
pair<int, int> xy[4];

int pv;
struct f {
	int x, y;
};

int bfs(int fr,int to,int ex_1,int ex_2) {
	
	queue<f>q;
	vis[xy[fr].first][xy[fr].second] = 0;
	q.push({ xy[fr].first,xy[fr].second });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		if (x == xy[to].first && y == xy[to].second)
			return vis[x][y];
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || nx>n || ny<0 || ny>m)
				continue;
			if (vis[nx][ny]!=-1)
				continue;
			if (nx == xy[ex_1].first&&ny == xy[ex_1].second)
				continue;
			if (nx == xy[ex_2].first&&ny == xy[ex_2].second)
				continue;
			vis[nx][ny] = vis[x][y] + 1;
			q.push({ nx,ny });
		}
	}
	return -1;
}
int vvis[105][105];

int bfs2(int a, int b, int c, int d) {
	queue<f>q;
	vvis[a][b] = 0;
	q.push({ a,b });

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		if (x == c && y == d)
			return vvis[c][d];


		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || nx>n || ny<0 || ny>m)
				continue;
			if (vvis[nx][ny]!=-1)
				continue;
			vvis[nx][ny] = vvis[x][y] + 1;
			q.push({ nx,ny });
		}
	}
	return -1;
}
void find(int dis, int fr, int to) {
	int x = xy[fr].first;
	int y = xy[fr].second;
	vvis[x][y] = 0;

	for (int i = dis-1; i >= 0; i--) {

		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx<0 || nx>n || ny<0 || ny>m)
				continue;
			if (vis[nx][ny] == i) {
				vvis[nx][ny] = 0;
				x = nx;
				y = ny;
				break;
			}
		}
	}
}
void input() {
	cin >> n >> m;
	ret = 1e9;
	int x, y;
	for (int i = 0; i < 4; i++) {
		cin >> x >> y;
		xy[i] = { x,y };
	}
	memset(vvis, -1, sizeof(vvis));
	memset(vis, -1, sizeof(vis));

	x=bfs(0,1,2,3);
	find(x,1, 0);
	y=bfs2(xy[2].first, xy[2].second, xy[3].first, xy[3].second);

	if (x!=-1&&y != -1)
		ret = x + y;

	memset(vvis, -1, sizeof(vvis));
	memset(vis, -1, sizeof(vis));

	x = bfs(2,3,0,1);
	find(x, 3,2);
	y = bfs2(xy[0].first, xy[0].second, xy[1].first, xy[1].second);

	if(x!=-1&&y!=-1)
		ret=min(ret,x+y);




	if (ret == 1e9) 
		cout << "IMPOSSIBLE";
	else
		cout << ret;
}
void solve() {

}
int main() {
	fastio;
	input();
	solve();

}




