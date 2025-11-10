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
int n, m, ret, t, k, Q;


vector<vector<int>> arr;


int mx, tmp;
vector<vector<int>> xy[2];
int pv;

struct f {
	int x, y, z;
};
void bfs(int a, int b, int c) {
	queue<f>q;
	q.push({ a,b,c });
	xy[c][a][b] = pv;

	while (!q.empty()) {
		f cur = q.front();
		q.pop();
		int x = cur.x;
		int y = cur.y;
		int z = cur.z;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (xy[0][nx][ny] == pv || xy[1][nx][ny] == pv)
				continue;

			if (i == 0) {
				if (z == 0) {
					tmp++;
					q.push({ nx,ny,1 });
					xy[1][nx][ny] = pv;
				}
			}
			else if (i == 1) {
				if (z == 1) {
					tmp++;
					q.push({ nx,ny,0 });
					xy[0][nx][ny] = pv;
				}
			}
			else if (i == 2) {
				if (arr[x][y] == -1) {
					if (z == 0) {
						if (arr[nx][ny] == 1) {
							tmp++;
							q.push({ nx,ny,0 });
							xy[0][nx][ny] = pv;
						}
						else {
							tmp++;
							q.push({ nx,ny,1 });
							xy[1][nx][ny]  =pv;
						}
					}
				}
				else {
					if (z == 1) {
						if (arr[nx][ny] == 1) {
							tmp++;
							q.push({ nx,ny,0 });
							xy[0][nx][ny] = pv;
						}
						else {
							tmp++;
							q.push({ nx,ny,1 });
							xy[1][nx][ny] = pv;
						}
					}

				}
			}
			else {
				if (arr[x][y] == -1) {
					if (z == 1) {
						if (arr[nx][ny] == 1) {
							tmp++;
							q.push({ nx,ny,1 });
							xy[1][nx][ny] = pv;
						}
						else {
							tmp++;
							q.push({ nx,ny,0 });
							xy[0][nx][ny] = pv;
						}
					}
				}
				else {
					if (z == 0) {
						if (arr[nx][ny] == 1) {
							tmp++;
							q.push({ nx,ny,1 });
							xy[1][nx][ny] = pv;
						}
						else {
							tmp++;
							q.push({ nx,ny,0 });
							xy[0][nx][ny] = pv;
						}
					}

				}
			}
		}
	}

	
}

int solution(vector<vector<int>> grid) {
	n = grid.size();
	m = grid[0].size();
	arr = grid;
	mx = -1;

	for (int i = 0; i < 2; i++) {
		xy[i].resize(n, vector<int>(m));
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int z = 0; z < 2; z++) {
				if (xy[z][i][j] == 0) {
					pv++;
					tmp = 1;
					bfs(i, j, z);
					mx = max(mx, tmp);
				}
			}
		}
	}


	return mx;
}


void input() {

}
void solve() {

}











