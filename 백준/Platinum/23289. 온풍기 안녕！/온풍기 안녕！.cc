#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include<iostream>
#include <string>
#include<deque>
#include <memory.h>
#include<vector>
#include<set>
#include<queue>
#include <cassert>
#include<algorithm>

using namespace std;

struct info {
	int x, y, d;
};
int w,r,c,k;
int arr[22][22];

int w_u[22][22];
int w_r[22][22];
int w_d[22][22];
int w_l[22][22];

vector<info> machine;
vector <pair<int, int>> check;
int choco;
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };

int dx1[3] = { -1,0,1 };
int dy1[3] = { 1,1,1 };

int dx2[3] = { -1,0,1 };
int dy2[3] = { -1,-1,-1 };

int dx3[3] = { -1,-1,-1 };
int dy3[3] = { -1,0,1 };

int dx4[3] = { 1,1,1 };
int dy4[3] = { -1,0,1 };


int josa() {
	for (int i = 0; i < check.size(); i++) {
		int x = check[i].first;
		int y = check[i].second;
		if (arr[x][y] < k)
			return 0;
	}
	return 1;
}

void wind() {
	int tmp[22][22] = { 0, };
	queue <info> q;

	for (int i = 0; i < machine.size(); i++) {
		memset(tmp, 0, sizeof(tmp));

		int x, y, d;
		x = machine[i].x;
		y = machine[i].y;
		d = machine[i].d;
		tmp[x + dx[d]][y + dy[d]] += 5;
		q.push({ x + dx[d],y+dy[d],5});

		while (!q.empty()) {
			int xx, yy, cnt;
			xx = q.front().x;
			yy = q.front().y;
			cnt = q.front().d;
			q.pop();
			if (cnt == 0)
				continue;
			for (int j = 0; j < 3; j++) {
				int nx, ny;
				if (d == 1) {
					nx = xx + dx1[j];
					ny = yy + dy1[j];
				}
				else if (d == 2) {
					nx = xx + dx2[j];
					ny = yy + dy2[j];
				}
				else if (d == 3) {
					nx = xx + dx3[j];
					ny = yy + dy3[j];
				}
				else{
					nx = xx + dx4[j];
					ny = yy + dy4[j];
				}

				if (nx<1 || nx>r || ny<1 || ny>c)
					continue;
				if (d == 1) {
					if (nx > xx) {
						if (w_d[xx][yy] == 1 || w_r[xx + 1][yy] == 1)
							continue;
					}
					else if (nx == xx) {
						if (w_r[xx][yy] == 1)
							continue;
					}
					else if (nx < xx) {
						if (w_u[xx][yy] == 1 || w_r[xx-1][yy] == 1)
							continue;
					}
				}

				else if (d == 2) {
					if (nx > xx) {
						if (w_d[xx][yy] == 1 || w_l[xx + 1][yy] == 1)
							continue;
					}
					else if (nx == xx) {
						if (w_l[xx][yy] == 1)
							continue;
					}
					else if (nx < xx) {
						if (w_u[xx][yy] == 1 || w_l[xx - 1][yy] == 1)
							continue;
					}
				}

				else if (d == 3) {
					if (ny > yy) {
						if (w_r[xx][yy] == 1 || w_u[xx][yy + 1] == 1)
							continue;
					}
					else if (ny == yy) {
						if (w_u[xx][yy] == 1)
							continue;
					}
					else if (ny < yy) {
						if (w_l[xx][yy] == 1 || w_u[xx][yy - 1] == 1)
							continue;
					}
				}
				else if (d == 4) {
					if (ny > yy) {
						if (w_r[xx][yy] == 1 || w_d[xx][yy + 1] == 1)
							continue;
					}
					else if (ny == yy) {
						if (w_d[xx][yy] == 1)
							continue;
					}
					else if (ny < yy) {
						if (w_l[xx][yy] == 1 || w_d[xx][yy - 1] == 1)
							continue;
					}
				}
				tmp[nx][ny] = cnt - 1;
				q.push({ nx,ny,cnt - 1 });
			}
		}
		
		for (int a = 1; a <= r; a++)
			for (int b = 1; b <= c; b++)
				arr[a][b] += tmp[a][b];
		/*
		for (int a = 1; a <= r; a++){
			for (int b = 1; b <= c; b++) {
				cout << tmp[a][b] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
		*/
	}

}
void decline() {
	int tmp[22][22] = { 0, };

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			tmp[i][j] = arr[i][j];
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			
			for (int z = 1; z <= 4; z++) {
				int x, y;
				x = i + dx[z];
				y = j + dy[z];
				if (x < 1 || x>r || y<1 || y>c)
					continue;
				if (arr[i][j] > arr[x][y]) {
					if (z == 1 && w_r[i][j] == 1)
						continue;
					else if (z == 2 && w_l[i][j] == 1)
						continue;
					else if (z == 3 && w_u[i][j] == 1)
						continue;
					else if (z == 4 && w_d[i][j] == 1)
						continue;

					int dif = (arr[i][j] - arr[x][y])/4;
				
					tmp[i][j] -= dif;
					tmp[x][y] += dif;
				}
			}
			
		
		}
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			 arr[i][j]=tmp[i][j];
		}
	}
	for (int i = 1; i <= r; i++) {
		if (arr[i][1] > 0)
			arr[i][1]--;
		if (arr[i][c] > 0)
			arr[i][c]--;
	}
	for (int i = 2; i <c; i++) {
		if (arr[1][i] > 0)
			arr[1][i]--;
		if (arr[r][i] > 0)
			arr[r][i]--;
	}
}
void pri() {
	
	for (int a = 1; a <= r; a++){
		for (int b = 1; b <= c; b++) {
			cout << arr[a][b] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
	
}
int main() {
	cin >> r >> c >> k;

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 5)
				check.push_back({ i,j });
			else if (arr[i][j] > 0)
				machine.push_back({ i,j,arr[i][j] });
			arr[i][j] = 0;
		}
	}
	cin >> w;
	
	for (int i = 0; i < w; i++) {
		int x, y, t;
		cin >> x >> y >> t;
		if (t == 0) {
			w_d[x - 1][y] =1;
			w_u[x][y] = 1;
		}
		else {
			w_r[x][y] = 1;
			w_l[x][y + 1] = 1;
		}
	}
	if (josa() == 1) {
		cout << 0;
		return 0;
	}
	while (1) {
		wind();
		decline();
		choco++;
		if (choco > 100) {
			choco = 101;
			break;
		}
		if (josa() == 1)
			break;
		
		
	}
	//pri();
	cout << choco;
}