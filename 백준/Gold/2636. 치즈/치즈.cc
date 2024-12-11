#include <stdio.h>
#include<iostream>
#include <string>
#include<queue>
#include <memory.h>
#include<vector>
#include<set>
using namespace std;


int r, c, n;
int arr[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int vis[101][101];
int tmp[101][101];
int re[101];

bool cango(int x, int y) {
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			vis[i][j] = 0;

	queue<pair<int, int>> q;
	q.push({ x,y });
	vis[x][y] = 1;

	while (!q.empty()) {
		int a = q.front().first;
		int b = q.front().second;
		q.pop();
		if (a == 0 || b == 0 || a == r - 1 || b == c - 1) {
			return 1;
		}
		for (int i = 0; i < 4; i++) {
			int nx = a + dx[i];
			int ny = b + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;
			if (vis[nx][ny])
				continue;
			if (arr[nx][ny])
				continue;
			q.push({ nx,ny });
			vis[nx][ny] = 1;
		}
	}
	return 0;
}
int main() {
	cin >> r >> c;
	int cnt = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
			if (arr[i][j])
				cnt++;
		}
	}

	re[0] = (cnt);

	int t = 0;

	while (1) {
		int flag = 0;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] == 1) {
					flag = 1;
					break;
				}
			}
		}

		if (flag == 0)
			break;


		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				tmp[i][j] = 0;
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j]) {
					int fflag = 0;

					for (int z = 0; z < 4; z++) {
						fflag = 1;
						break;
					}


					if (fflag) {

						//x,y가 x를만날수 있는지
						if (cango(i, j)) {
							tmp[i][j] = 1;
						}
					}

				}
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (tmp[i][j])
				arr[i][j] = 0;
		}
	}
	int tt = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j])
				tt++;
		}
	}
	t++;
	re[t] = tt;
}
	
	cout << t << "\n";
	if (t == 0)
		cout << re[0];
	else
		cout << re[t - 1];

}