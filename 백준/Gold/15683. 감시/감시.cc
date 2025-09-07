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
using namespace std;
using ll = long long;

int dx[4] = { -1,1,0,0};
int dy[4] = { 0,0,1,-1 };

int n, m,k,ret;
int arr[8][8];
struct f {
	int x, y, num;
};
f info[8];

int dir[8];
int idx;
void input() {
	cin >> n>>m;
	ret = 1e9;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] >= 1 && arr[i][j] <= 5)
				info[idx++] = { i,j,arr[i][j] };
		}
	}
}
int cpy[8][8];
void cal() {
	memcpy(cpy, arr, sizeof(arr));
	for (int i = 0; i < idx; i++) {
		int x = info[i].x;
		int y = info[i].y;
		int num = info[i].num;
		int d = dir[i];

		if (num == 1) {
			for (int i = 0; i < 8; i++) {
				int nx = x + dx[d] * i;
				int ny = y + dy[d] * i;
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					break;
				cpy[nx][ny] = -1;
				if (arr[nx][ny] == 6)
					break;
			}
		}
		else if (num == 2) {
			if (d == 0 || d == 1) {
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[0] * i;
					int ny = y + dy[0] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[1] * i;
					int ny = y + dy[1] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
			}
			else {
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[2] * i;
					int ny = y + dy[2] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[3] * i;
					int ny = y + dy[3] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
			}
		}

		else if (num == 3) {
			if (d == 0) {
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[0] * i;
					int ny = y + dy[0] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[2] * i;
					int ny = y + dy[2] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
			}
			else if (d == 1) {
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[1] * i;
					int ny = y + dy[1] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[3] * i;
					int ny = y + dy[3] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
			}
			else if (d == 2) {
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[1] * i;
					int ny = y + dy[1] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[2] * i;
					int ny = y + dy[2] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
			}
			else if (d == 3) {
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[0] * i;
					int ny = y + dy[0] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[3] * i;
					int ny = y + dy[3] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
			}
		}

		else if (num == 4) {
			if (d == 0) {
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[0] * i;
					int ny = y + dy[0] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[2] * i;
					int ny = y + dy[2] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[3] * i;
					int ny = y + dy[3] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
			}
			else if (d == 1) {
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[3] * i;
					int ny = y + dy[3] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[2] * i;
					int ny = y + dy[2] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[1] * i;
					int ny = y + dy[1] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
			}
			else if (d == 2) {
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[0] * i;
					int ny = y + dy[0] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[2] * i;
					int ny = y + dy[2] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[1] * i;
					int ny = y + dy[1] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
			}
			else if (d == 3) {
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[0] * i;
					int ny = y + dy[0] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[3] * i;
					int ny = y + dy[3] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[1] * i;
					int ny = y + dy[1] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
			}

		}
		else if (num == 5) {
			for (int j = 0; j < 4; j++) {
				for (int i = 0; i < 8; i++) {
					int nx = x + dx[j] * i;
					int ny = y + dy[j] * i;
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						break;
					cpy[nx][ny] = -1;
					if (arr[nx][ny] == 6)
						break;
				}
			}
		}
	}

	
	int re = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (cpy[i][j] == 0)
				re++;
		}
	}
	ret = min(ret, re);
}

void dfs(int dep) {
	if (dep == idx) {
		cal();
		return;
	}

	if (info[dep].num == 2) {
		for (int i = 0; i < 4; i += 2) {
			dir[dep] = i;
			dfs(dep + 1);
		}
	}
	else if (info[dep].num == 5) {
			dfs(dep + 1);
	}
	else {
		for (int i = 0; i < 4; i++) {
			dir[dep] = i;
			dfs(dep + 1);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	dfs(0);
	cout << ret;
}
