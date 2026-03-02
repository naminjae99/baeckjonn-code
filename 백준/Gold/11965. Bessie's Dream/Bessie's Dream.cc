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


int dx[9] = { -1,1,0,0 };
int dy[9] = { 0,0,-1,1 };

int m, ret, t, k, Q, n;
int arr[1005][1005];
int d[1005][1005][2];

struct f {
	int x, y, smell, cost;
	bool operator<(const f& o)const {
		return cost > o.cost;
	}
};

void input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			d[i][j][0] = d[i][j][1] = 1e9;
		}
	}

	priority_queue<f>q;
	q.push({ 0,0,0,0 });
	d[0][0][0] = 0;

	while (!q.empty()) {
		int x = q.top().x;
		int y = q.top().y;
		int smell = q.top().smell;
		int cost = q.top().cost;
		q.pop();
			//cout << x << "," << y <<":"<<cost <<"에서\n";
		if (d[x][y][smell] != cost)
			continue;

		if (x == n - 1 && y == m - 1) {
			cout << cost;
			return;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (arr[nx][ny] == 0)
				continue;
			else if (arr[nx][ny] == 1) {
				if (d[nx][ny][smell] > cost + 1) {
					q.push({ nx,ny,smell,cost + 1 });
					d[nx][ny][smell] = cost + 1;
				}
			}
			else if (arr[nx][ny] == 2) {
				if (d[nx][ny][1] > cost + 1) {
					q.push({ nx,ny,1,cost + 1 });
					d[nx][ny][1] = cost + 1;
				}
			}
			else if (arr[nx][ny] == 3) {
				if (smell == 1 && d[nx][ny][smell] > cost + 1) {
					q.push({ nx,ny,smell,cost + 1 });
					d[nx][ny][smell] = cost + 1;
				}
			}
			else if (arr[nx][ny] == 4) {
				int nnx, nny;
				int ncost = cost + 1;

				while (1) {
					nnx = nx + dx[i];
					nny = ny + dy[i];
					if (nnx < 0 || nny < 0 || nnx >= n || nny >= m)
						break;
					if (arr[nnx][nny] == 4) {
						nx = nnx, ny = nny;
						ncost++;
						continue;
					}
					else if (arr[nnx][nny] == 0)
						break;
					else if (arr[nnx][nny] == 3) {
						if (smell == 1) {
							ncost++;
							nx = nnx, ny = nny;
							break;
						}
						else
							break;
					}
					else {
						ncost++;
						nx = nnx, ny = nny;
						break;
					}

				}
				//cout << nx << "," << ny << "로 가는거"<<ncost<<" 추가\n";
				if (arr[nx][ny] == 2) 
					smell = 1;
				
				if (d[nx][ny][smell] > ncost) {
					q.push({ nx,ny,smell,ncost });
					d[nx][ny][smell] = ncost;
				}

			}

		}
	}
	cout << -1;
}



int main() {
	fastio
		input();

}