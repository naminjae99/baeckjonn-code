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
#include<cfloat>
using namespace std;
using ll = long long;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int n, m, t, ret, h, k;
int arr[11][11];
pair<int, int> xy[105];

pair<int, int> knight[8] = { {-2,-1},{-2,1},{-1,-2},{-1,2}
,{1,-2},{1,2},{2,1},{2,-1} };

int ddx[4] = { -1,-1,1,1 };
int ddy[4] = { -1,1,-1,1 };



struct f {
	int x, y, pre, cost, mode;
};
bool vis[3][105][11][11];
bool bound(int nx, int ny) {
	if (nx < 0 || nx >= n || ny < 0 || ny >= n)
		return 0;
	return 1;
}
void input() {
	ret = 1e9;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			xy[arr[i][j]] = { i,j };
		}
	}

	queue<f>q;
	for (int i = 0; i < 3; i++) {
		q.push({ xy[1].first,xy[1].second,1,0,i });
		vis[i][1][xy[1].first][xy[1].second] = 1;
	}
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int pre = q.front().pre;
		int cost = q.front().cost;
		int mode = q.front().mode;
		q.pop();
	

		if (pre == n * n) {
			ret = min(ret, cost);
		}
		if (mode == 0) {
			for (int i = 0; i < 8; i++) {
				int nx = x + knight[i].first;
				int ny = y + knight[i].second;
				int next = pre;
				if (!bound(nx, ny))
					continue;;
				if (arr[nx][ny] == next+1)
					next++;
				if (vis[mode][next][nx][ny])
					continue;
				vis[mode][next][nx][ny] = 1;
				q.push({ nx,ny,next,cost + 1,mode });
			}
		}
		else if (mode == 1) {
			for (int i = 0; i < 4; i++) {
				for (int s = 1;; s++) {
					int nx = x + s * dx[i];
					int ny = y + s * dy[i];
					int next = pre;
					if (!bound(nx, ny))
						break;
					if (arr[nx][ny] == next + 1)
						next++;
					if (vis[mode][next][nx][ny])
						continue;
					vis[mode][next][nx][ny] = 1;
					q.push({ nx,ny,next,cost + 1,mode });
				}
			}
		}
		else if (mode == 2) {
			for (int i = 0; i < 4; i++) {
				for (int s = 1;; s++) {
					int nx = x + s * ddx[i];
					int ny = y + s * ddy[i];
					int next = pre;
					if (!bound(nx, ny))
						break;
					if (arr[nx][ny] == next + 1)
						next++;
					if (vis[mode][next][nx][ny])
						continue;
					vis[mode][next][nx][ny] = 1;
					q.push({ nx,ny,next,cost + 1,mode });
				}
			}
		}
		for (int i = 0; i < 3; i++) {
			if (i == mode)
				continue;
			if (vis[i][pre][x][y])
				continue;
			vis[i][pre][x][y] = 1;
			q.push({ x,y,pre,cost + 1,i });
		}
	}
}

void move() {


}


void solve() {


	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	input();
	solve();
	cout << ret;

}
