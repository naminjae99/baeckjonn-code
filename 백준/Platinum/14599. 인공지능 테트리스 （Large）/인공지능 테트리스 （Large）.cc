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

int m, ret, t, k, Q, n, L;
int arr[21][11];
// 음수 제거 완료 (코드로 검증됨)
int blockx[19][4] = {
    {0,0,1,2},
    {0,0,0,1},
    {0,1,2,2},  // 수정: blocky {0,0,0,-1} → {1,1,1,0}
    {0,1,1,1},
    {0,0,1,2},
    {0,1,1,1},  // 수정: blocky {0,0,-1,-2} → {2,2,1,0}
    {0,1,2,2},
    {0,0,0,1},
    {0,1,2,3},
    {0,0,0,0},
    {0,0,1,1},
    {0,1,1,2},
    {1,1,1,0},  // 수정: blockx {0,0,0,-1} → {1,1,1,0}
    {0,1,1,2},  // 수정: blocky {0,-1,0,0} → {1,0,1,1}
    {0,0,0,1},  // 수정: blocky {0,1,0,-1} 없음 → bn=14가 원래 bn=15
    {0,1,1,2},
    {0,0,1,1},  // 수정: blocky {0,1,0,-1} → {1,2,1,0}
    {0,1,1,2},  // 수정: blocky {0,-1,0,-1} → {1,0,1,0}
    {0,0,1,1}
};

int blocky[19][4] = {
    {0,1,0,0},
    {0,1,2,2},
    {1,1,1,0},  // 수정
    {0,0,1,2},
    {0,1,1,1},
    {2,2,1,0},  // 수정
    {0,0,0,1},
    {0,1,2,0},
    {0,0,0,0},
    {0,1,2,3},
    {0,1,0,1},
    {0,0,1,0},
    {0,1,2,1},  // 수정
    {1,0,1,1},  // 수정
    {0,1,2,1},
    {0,0,1,1},
    {1,2,1,0},  // 수정
    {1,0,1,0},  // 수정
    {0,1,1,2}
};
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool out(int x, int y) {
	return x < 0 || x >= n || y < 0 || y >= m;
}
int vis[21][11][19];
int cpy[21][11];
void cal(int x, int y, int bn) {
	memcpy(cpy, arr, sizeof(arr));
	for (int bc = 0; bc < 4; bc++) {
		int nx = x + blockx[bn][bc];
		int ny = y + blocky[bn][bc];
		cpy[nx][ny] = 1;
	}
	int re = 0;
		for (int i = n - 1; i >= 0; i--) {
			int cnt = 0;
			for (int j = 0; j < m; j++) {
				if (cpy[i][j])
					cnt++;
			}
			if (cnt == m) {

				re++;
				
			}
		}

	
	ret = max(re, ret);

}
void input() {
	n = 20;
	m = 10;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';
		}
	}


	for (int bn = 0; bn < 19; bn++) {
		queue<pair<int, int>>q;

		for (int j = 0; j < m; j++) {
			int x = 0;
			int y = j;
			bool flag = 0;
			for (int bc = 0; bc < 4; bc++) {
				int nx = x + blockx[bn][bc];
				int ny = y + blocky[bn][bc];
				if (out(nx, ny)) {
					flag = 1;
					break;
				}
				if (arr[nx][ny]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0) {
				vis[x][y][bn] = 1;
				q.push({ x,y });
			}
		}


		//cout << bn << "번 블록\n";
		while (!q.empty()) {
			int a = q.front().first;
			int b = q.front().second;
			q.pop();

			for (int dir = 0; dir < 2; dir++) {
				int sx = a + dx[dir];
				int sy = b + dy[dir];
				bool can = 0;
				if (out(sx, sy))
					continue;
				for (int bc = 0; bc < 4; bc++) {
					int nx = sx + blockx[bn][bc];
					int ny = sy + blocky[bn][bc];
					if (out(nx, ny)) {
						can = 1;
						break;
					}
					if (arr[nx][ny]) {
						can = 1;
						break;
					}
				}
				if (can == 0 && vis[sx][sy][bn] == 0) {
					vis[sx][sy][bn] = 1;
					q.push({ sx,sy });
				}
			}

			bool down = 0;
			int sx = a + 1;
			int sy = b;
			if (out(sx, sy)) {
				cal(a, b, bn);
				continue;
			}
		
			for (int bc = 0; bc < 4; bc++) {
				int nx = sx + blockx[bn][bc];
				int ny = sy + blocky[bn][bc];
				if (out(nx, ny)) {
					down = 1;
					break;
				}
				if (arr[nx][ny]) {
					down = 1;
					break;
				}
			}
			//못내려가면 넣고 계산
			if (down) {

				cal(a, b, bn);

			}
			else {
				if (vis[sx][sy][bn] == 0) {
					vis[sx][sy][bn] = 1;
					q.push({ sx,sy });
				}
			}

		}
	}

	cout << ret;
}
void run() {


}


int main() {
	fastio
		input();
	run();

}