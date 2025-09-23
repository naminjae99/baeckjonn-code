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

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };


int n, m, t, k, ret;
int qx[1000005];
int qy[1000005];
int fr, ba;
int vis[105][105];
bool arr[105][105];
int solution(vector<vector<int> > maps){
	
	memset(vis, -1, sizeof(vis));
	n = maps.size();
	m = maps[0].size();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			arr[i][j] = maps[i][j];

	qx[ba] = 0;
	qy[ba++] = 0;
	vis[0][0] = 1;

	while (fr < ba) {
		int x = qx[fr];
		int y = qy[fr++];

		if (x == n-1 && y == m-1) {
			return vis[x][y];
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || nx>=n || ny<0 || ny>=m)
				continue;
			if (vis[nx][ny]!=-1 || arr[nx][ny]==0)
				continue;
			qx[ba] = nx;
			qy[ba++] = ny;
			vis[nx][ny] = vis[x][y]+1;
		}
	}

	return -1;
}