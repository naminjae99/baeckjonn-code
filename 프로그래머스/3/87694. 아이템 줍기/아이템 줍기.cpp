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

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


int n, m, t, k, ret;
int sqcnt;
vector<int> line[55][55];
int pob[55][55][4];

struct Node {
	int x, y;
};
int vis[55][55];
queue<Node>q;
int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
	sqcnt = rectangle.size();
	memset(vis, -1, sizeof(vis));
	for (int i = 0; i < sqcnt; i++) {
		int sx = rectangle[i][0];
		int sy = rectangle[i][1];
		int ex = rectangle[i][2];
		int ey = rectangle[i][3];

		

		for (int a = sx; a < ex; a++) {
			line[a][sy].push_back(2);
			line[a][ey].push_back(2);
		}
		for (int a = sx + 1; a <= ex; a++) {
			line[a][sy].push_back(0);
			line[a][ey].push_back(0);
		}
		for (int b = sy; b < ey; b++) {
			line[sx][b].push_back(1);
			line[ex][b].push_back(1);
		}
		for (int b = sy + 1; b <= ey; b++) {
			line[sx][b].push_back(3);
			line[ex][b].push_back(3);
		}

		for (int a = sx + 1; a < ex; a++) {
			pob[a][sy][1] = 1;
			pob[a][ey][3] = 1;
		}
		for (int b = sy + 1; b < ey; b++) {
			pob[sx][b][2]=1;
			pob[ex][b][0]=1;
		}
		for (int a = sx + 1; a < ex; a++) {
			for (int b = sy + 1; b < ey; b++) {
				vis[a][b] = 0;
			}
		}
	}

		q.push({ characterX, characterY });

	vis[characterX][characterY] = 0;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;

		q.pop();

		if (x == itemX && y == itemY) {
			return vis[x][y];
		}



		for (auto dir : line[x][y]) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (nx < 1 || nx > 50 || ny < 1 || ny > 50) continue;
			if (vis[nx][ny] != -1) continue; // 이미 방문
			if (pob[x][y][dir])continue;
			if (line[nx][ny].empty()) continue; // 이동 불가

		
				vis[nx][ny] = vis[x][y] + 1;
				q.push({ nx, ny });

			
		}
		
	}

}