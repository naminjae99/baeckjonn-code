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
int n,m, ret, t, k, Q, L;

int dx[8] = { 0,1,0,-1};
int dy[8] = { 1,0,-1,0 };
char arr[105][105];

int cx, cy, dp;
bool cc;
int vis[105][105];
int pv;

bool out(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= m;
}
void input() {
	cin >> n >> m;

	cc = 0;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
		}
	}


	while (1) {
		
	//	cout << arr[cx][cy] << ": ";
	//	cout << cx << "," << cy <<",dp:"<<dp<<",cc:"<<cc <<"\n";
		cout << arr[cx][cy];
		//cx cy에서  dp방향으로 가서 만난끝점들 저장
		++pv;
		queue<pair<int, int>>q;
		q.push({ cx,cy });
		vis[cx][cy] = pv;

		int bound_xy[4];
		vector<pair<int, int>> xy[4];
		bound_xy[0] = -1, bound_xy[1] = -1;
		bound_xy[2] = bound_xy[3] = n;

		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();

			if (bound_xy[0] < y) {
				xy[0].clear();
				xy[0].push_back({ x,y });
				bound_xy[0] = y;
			}
			else if (bound_xy[0] == y)
				xy[0].push_back({ x,y });

			if (bound_xy[1] < x) {
				xy[1].clear();
				xy[1].push_back({ x,y });
				bound_xy[1] = x;
			}
			else if (bound_xy[1] == x)
				xy[1].push_back({ x,y });

			if (bound_xy[2] >y) {
				xy[2].clear();
				xy[2].push_back({ x,y });
				bound_xy[2] = y;
			}
			else if (bound_xy[2] == y)
				xy[2].push_back({ x,y });

			if (bound_xy[3] > x) {
				xy[3].clear();
				xy[3].push_back({ x,y });
				bound_xy[3] = x;
			}
			else if (bound_xy[3] == x)
				xy[3].push_back({ x,y });

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (out(nx, ny))
					continue;
				if (vis[nx][ny] == pv || arr[nx][ny] != arr[cx][cy])
					continue;
				q.push({ nx,ny });
				vis[nx][ny] = pv;
			}
		}

		bool flag = 0;
		for (int i = 0; i < 4; i++) {
			if (flag)
				break;
			for (int j = 0; j < 2; j++) {
				int mx, my;
				if (dp == 0) {
					if (cc == 0) {
						mx = n;
						for (auto c : xy[0]) {
							if (mx > c.first)
								mx = c.first, my = c.second;
						}
					}
					else {
						mx = -1;
						for (auto c : xy[0]) {
							if (mx < c.first)
								mx = c.first, my = c.second;
						}
					}
					
					int nx = mx + dx[dp];
					int ny = my + dy[dp];
					if (out(nx, ny) || arr[nx][ny] == 'X') {
						if (j == 0) {
							if (cc == 1)
								cc = 0;
							else
								cc = 1;
						}
							
						else
							dp = (dp + 1) % 4;
					}
					else {
						flag = 1;
						cx = nx, cy = ny;
						break;
					}
				}
				else if (dp == 1) {
					if (cc == 0) {
						my = -1;
						for (auto c : xy[1]) {
							if (my < c.second)
								mx = c.first, my = c.second;
						}
					}
					else {
						my = n;
						for (auto c : xy[1]) {
							if (my>c.second)
								mx = c.first, my = c.second;
						}
					}

					int nx = mx + dx[dp];
					int ny = my + dy[dp];
					if (out(nx, ny) || arr[nx][ny] == 'X') {
						if (j == 0) {
							if (cc == 1)
								cc = 0;
							else
								cc = 1;
						}
						else
							dp = (dp + 1) % 4;
					}
					else {
						flag = 1;
						cx = nx, cy = ny;
						break;
					}
				}
				else if (dp == 2) {
					if (cc == 0) {
						mx = -1;
						for (auto c : xy[2]) {
							if (mx < c.first)
								mx = c.first, my = c.second;
						}
					}
					else {
						mx = n;
						for (auto c : xy[2]) {
							if (mx > c.first)
								mx = c.first, my = c.second;
						}
					}

					int nx = mx + dx[dp];
					int ny = my + dy[dp];
					if (out(nx, ny) || arr[nx][ny] == 'X') {
						if (j == 0) {
							if (cc == 1)
								cc = 0;
							else
								cc = 1;
						}
						else
							dp = (dp + 1) % 4;
					}
					else {
						flag = 1;
						cx = nx, cy = ny;
						break;
					}
				}
				else if (dp == 3) {
					if (cc == 0) {
						my = n;
						for (auto c : xy[3]) {
							if (my > c.second)
								mx = c.first, my = c.second;
						}
					}
					else {
						my = -1;
						for (auto c : xy[3]) {
							if (my < c.second)
								mx = c.first, my = c.second;
						}
					}
		
					int nx = mx + dx[dp];
					int ny = my + dy[dp];
					if (out(nx, ny) || arr[nx][ny] == 'X') {
						if (j == 0) {
							if (cc == 1)
								cc = 0;
							else
								cc = 1;
						}
						else
							dp = (dp + 1) % 4;
					}
					else {
						flag = 1;
						cx = nx, cy = ny;
						break;
					}
				}
			}
		}
		if (flag == 0)
			break;

	}
}



void run() {


}


int main() {
	fastio
		input();
	run();

}
