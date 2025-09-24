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

int dx[4] = {-1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


int n, m, t, k, ret;

int sqcnt;

int arr[105][105];

struct Node {
	int x, y;
};
int fr, ba;
int vis[105][105];

queue<Node>q;
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
	sqcnt = rectangle.size();
	memset(vis, -1, sizeof(vis));
	characterX *= 2, characterY *= 2;
	itemX *= 2, itemY *= 2;
	for (int i = 0; i < sqcnt; i++) {
		int sx = rectangle[i][0]*2;
		int sy = rectangle[i][1] * 2;
		int ex = rectangle[i][2] * 2;
		int ey = rectangle[i][3] * 2;

		for (int a = sx ; a <= ex; a++) {
			for (int b = sy ; b <= ey; b++) {
				arr[a][b] = 1;
			}
		}

		for (int a = sx + 1; a < ex; a++) {
			for (int b = sy + 1; b < ey; b++) {
				vis[a][b] = 0;
			}
		}
	}
	q.push({ characterX,characterY });
	vis[characterX][characterY] = 0;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		if (x == itemX && y == itemY) {
			return vis[x][y]/2;
		}


		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (vis[nx][ny] != -1)
				continue;
			if (arr[nx][ny] == 0)
				continue;
			q.push({ nx,ny });
			vis[nx][ny] = vis[x][y] + 1;
		}
	}
}