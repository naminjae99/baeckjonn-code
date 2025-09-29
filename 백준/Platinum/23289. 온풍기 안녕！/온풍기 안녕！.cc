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
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

int ddx[4][3] = { {-1,0,1},{-1,-1,-1},{-1,0,1},{1,1,1} };
int ddy[4][3] = { {-1,-1,-1},{-1,0,1},{1,1,1},{-1,0,1} };
int n, m, ret, k;
int arr[25][25];

vector<pair<int, int>> chk;
vector<pair<int, int>> air[4];
int wall[25][25][25][25];
int vis[25][25];
int wing[25][25];

void input() {
	cin >> n >> m >> k;
	int x, y, z;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> x;
			if (x == 5)
				chk.push_back({ i,j });
			else if (x == 2)
				air[0].push_back({ i,j });
			else if (x == 3)
				air[1].push_back({ i,j });
			else if (x == 1)
				air[2].push_back({ i,j });
			else if (x == 4)
				air[3].push_back({ i,j });
		}
	}
	int mm;
	cin >> mm;
	while (mm--) {
		cin >> x >> y >> z;
		if (z == 0) {
			wall[x - 1][y - 1][x - 2][y - 1] = wall[x - 2][y - 1][x - 1][y - 1] = 1;
		}
		else {
			wall[x - 1][y - 1][x - 1][y] = wall[x - 1][y][x - 1][y - 1] = 1;
		}
	}

}
bool check() {
	for (auto c : chk) {
		if (arr[c.first][c.second] < k)
			return 0;
	}
	return 1;
}
void blow(int x, int y, int dir) {
	memset(vis, 0, sizeof(vis));
	queue<pair<int, int>> q;
	int nx = x + ddx[dir][1];
	int ny = y + ddy[dir][1];
	q.push({ nx,ny });
	vis[nx][ny] = 1;
	wing[nx][ny] += 5;

	if (dir == 0) {
		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();
			if (y-b == 5)
				continue;

			nx = a + ddx[dir][0];
			ny = b + ddy[dir][0];
			if (!(nx < 0 || nx >= n || ny < 0 || ny >= m)) {
				if (vis[nx][ny] == 0) {
					if (!wall[a][b][a - 1][b] && !wall[a - 1][b][a - 1][b - 1]) {
						vis[nx][ny] = 1;
						q.push({ nx,ny });
						wing[nx][ny] += 6 - (y - ny);
					}
				}
			}

			nx = a + ddx[dir][1];
			ny = b + ddy[dir][1];
			if (!(nx < 0 || nx >= n || ny < 0 || ny >= m)) {
				if (vis[nx][ny] == 0) {
					if (!wall[a][b][a][b - 1]) {
						vis[nx][ny] = 1;
						q.push({ nx,ny });
						wing[nx][ny] += 6 - (y - ny);
					}
				}
			}
			nx = a + ddx[dir][2];
			ny = b + ddy[dir][2];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (vis[nx][ny])continue;

			if (!wall[a][b][a + 1][b] && !wall[a + 1][b][a + 1][b - 1]) {
				vis[nx][ny] = 1;
				q.push({ nx,ny });
				wing[nx][ny] += 6 - (y - ny);
			}


		}
	}
	else if (dir == 2) {
		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();
			if (b-y == 5)
				continue;

			nx = a + ddx[dir][0];
			ny = b + ddy[dir][0];
			if (!(nx < 0 || nx >= n || ny < 0 || ny >= m)) {
				if (vis[nx][ny] == 0) {
					if (!wall[a][b][a - 1][b] && !wall[a - 1][b][a - 1][b + 1]) {
						vis[nx][ny] = 1;
						q.push({ nx,ny });
						wing[nx][ny] += 6 - (ny - y);
					}
				}
			}
			nx = a + ddx[dir][1];
			ny = b + ddy[dir][1];

			if (!(nx < 0 || nx >= n || ny < 0 || ny >=m)) {
				if (vis[nx][ny] == 0) {
					if (!wall[a][b][a][b + 1]) {
						vis[nx][ny] = 1;
						q.push({ nx,ny });
						wing[nx][ny] += 6 - (ny - y);
					}
				}
			}
			nx = a + ddx[dir][2];
			ny = b + ddy[dir][2];

			if (!(nx < 0 || nx >= n || ny < 0 || ny >= m)) {
				if (vis[nx][ny] == 0) {
					if (!wall[a][b][a + 1][b] && !wall[a + 1][b][a + 1][b + 1]) {
						vis[nx][ny] = 1;
						q.push({ nx,ny });
						wing[nx][ny] += 6 - (ny - y);
					}
				}
			}

		}
	}
	else if (dir == 1) {
		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();

			if (x-a == 5)
				continue;

			nx = a + ddx[dir][0];
			ny = b + ddy[dir][0];
			if (!(nx < 0 || nx >= n || ny < 0 || ny >= m)) {
				if (vis[nx][ny] == 0) {
					if (!wall[a][b][a][b - 1] && !wall[a][b - 1][a - 1][b - 1]) {
						vis[nx][ny] = 1;
						q.push({ nx,ny });
						wing[nx][ny] += 6 - (x - nx);
					}
				}
			}
			nx = a + ddx[dir][1];
			ny = b + ddy[dir][1];
			if (!(nx < 0 || nx >= n || ny < 0 || ny >=m)) {
				if (vis[nx][ny] == 0) {
					if (!wall[a][b][a - 1][b]) {
						vis[nx][ny] = 1;
						q.push({ nx,ny });
						wing[nx][ny] += 6 - (x - nx);
					}
				}
			}
			nx = a + ddx[dir][2];
			ny = b + ddy[dir][2];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (vis[nx][ny])continue;

			if (!wall[a][b][a][b + 1] && !wall[a][b + 1][a - 1][b + 1]) {
				vis[nx][ny] = 1;
				q.push({ nx,ny });
				wing[nx][ny] += 6 - (x - nx);
			}


		}
	}
	else if (dir == 3) {
		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();

			if (a-x == 5)
				continue;
			nx = a + ddx[dir][0];
			ny = b + ddy[dir][0];
			if (!(nx < 0 || nx >= n || ny < 0 || ny >= m)) {
				if (vis[nx][ny] == 0) {
					if (!wall[a][b][a][b - 1] && !wall[a][b - 1][a + 1][b - 1]) {
						vis[nx][ny] = 1;
						q.push({ nx,ny });
						wing[nx][ny] += 6 - (nx - x);
					}
				}
			}
			nx = a + ddx[dir][1];
			ny = b + ddy[dir][1];
			if (!(nx < 0 || nx >= n || ny < 0 || ny >= m)) {
				if (vis[nx][ny] == 0) {
					if (!wall[a][b][a + 1][b]) {
						vis[nx][ny] = 1;
						q.push({ nx,ny });
						wing[nx][ny] += 6 - (nx - x);
					}
				}
			}

			nx = a + ddx[dir][2];
			ny = b + ddy[dir][2];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
			if (vis[nx][ny])continue;

			if (!wall[a][b][a][b + 1] && !wall[a][b + 1][a + 1][b + 1]) {
				vis[nx][ny] = 1;
				q.push({ nx,ny });
				wing[nx][ny] += 6 - (nx - x);
			}


		}
	}

}
void first() {
	for (int ct = 0; ct < 4; ct++) {
		for (auto c : air[ct]) {
			blow(c.first, c.second, ct);
		}
	}
}
void add() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] += wing[i][j];
		}
	}
}
int cpy[25][25];
void mix() {
	memcpy(cpy, arr, sizeof(arr));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			for (int z = 0; z < 4; z++) {
				int nx = i + dx[z];
				int ny = j + dy[z];
				if (nx < 0 || nx >= n || ny < 0 || ny >=m)continue;
				if (cpy[i][j] <= cpy[nx][ny])
					continue;
				if (wall[i][j][nx][ny])
					continue;
				int dif = (cpy[i][j] - cpy[nx][ny]) / 4;
				if (dif == 0)
					continue;
				arr[i][j] -= dif;
				arr[nx][ny] += dif;
			}

		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i][0])
			arr[i][0]--;
		if (arr[i][m - 1])
			arr[i][m - 1]--;
	}
	for (int i = 1; i < m - 1; i++) {
		if (arr[0][i])
			arr[0][i]--;
		if (arr[n - 1][i])
			arr[n - 1][i]--;
	}
}
void solve() {
	first();
	while (1) {
		if (check())
			break;
		ret++;
		if (ret > 100) 
			break;
		add();

		mix();
		
	}
}
int main() {
	fastio;
	input();
	solve();
	cout << ret;
	return 0;
}

