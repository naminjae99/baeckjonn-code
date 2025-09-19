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
#include<iomanip>
#include<deque>
#include<array>
#include<limits.h>
#include<cfloat>
using namespace std;
using ll = long long;
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

int n, m, k, ret, h;
int arr[25][25];
int cx, cy,coil;
struct Node {
	int sx, sy, ex, ey,del;
};
Node info[405];
int vis[25][25];

void input() {
	cin >> n >> m >> coil;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	cin >> cx >> cy;
	for (int i = 2; i <= m+1; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		info[i] = { a,b,c,d,0 };
		arr[a][b] = i;
	}
	
}

pair<int,int> find() {
	memset(vis, -1, sizeof(vis));

	//가장 가까운 고객
	queue<pair<int, int>> q;
	q.push({ cx,cy });
	vis[cx][cy] = 0;

	int idx = -1;
	int md=1e9,mx = n, my = n;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (arr[x][y]&&info[arr[x][y]].del==0) {
			if (md == vis[x][y]) {
				if (mx == x) {
					if (my > y) {
						my = y, idx = arr[x][y];
					}
				}
				else if (mx > x) {
					mx=x,my = y, idx = arr[x][y];
				}
			}
			else if (md > vis[x][y]) {
				md=vis[x][y],mx=x,my = y, idx = arr[x][y];
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || nx>n || ny<1 || ny>n)
				continue;
			if (vis[nx][ny]!=-1 || arr[nx][ny] == 1)
				continue;
			q.push({ nx,ny });
			vis[nx][ny] = vis[x][y]+1;
		}
	}

	if (idx == -1)
		return { -1,-1 };
	return { idx,md };
}

int get_dis(int x) {
	memset(vis, -1, sizeof(vis));

	int sx, sy, ex, ey;
	sx = info[x].sx, sy = info[x].sy;
	ex = info[x].ex, ey = info[x].ey;

	queue<pair<int, int>> q;
	q.push({ sx,sy });
	vis[sx][sy] = 0;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x==ex&&y==ey) {
			return vis[x][y];
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<1 || nx>n || ny<1 || ny>n)
				continue;
			if (vis[nx][ny] != -1 || arr[nx][ny] == 1)
				continue;
			q.push({ nx,ny });
			vis[nx][ny] = vis[x][y] + 1;
		}
	}
	return -1;
}
void solve() {
	while (1) {

		pair<int,int> pas=find();
		int idx = pas.first;
		int dis = pas.second;

	//	cout << idx << "번 , " << dis << "의 거리 찾음\n";
		if (idx == -1)
			break;
		//태우러가다 연료 소진
		if (coil < dis) {
			coil = -1;
			break;
		}
		arr[info[idx].sx][info[idx].sy] = 0;


		coil -= dis;

		int dist_dis = get_dis(idx);
		//cout << idx << "번 , " << dist_dis << "의 도착 까지 거리\n";
		if (dist_dis == -1|| coil < dist_dis) {
			coil = -1;
			break;
		}
		coil += dist_dis;
		info[idx].del = 1;
		cx = info[idx].ex, cy = info[idx].ey;
	}
	
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	solve();

	for (int i = 2; i <= m + 1; i++) {
		if (info[i].del == 0) {
			coil = -1;
			break;
		}
	}
	cout << coil;
	return 0;
}