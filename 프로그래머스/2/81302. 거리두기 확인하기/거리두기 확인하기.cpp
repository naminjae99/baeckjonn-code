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


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m, ret, t;
char arr[5][5];
int vis[5][5];
int pv;

struct f {
	int x, y, z;
};
bool bfs(int a, int b) {
	pv++;
	queue<f>q;
	q.push({ a,b,0 });
	vis[a][b] = pv;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int len = q.front().z;
		q.pop();

		if (len >= 2)
			return 0;

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
				continue;
			if (vis[nx][ny] == pv)
				continue;
			if (arr[nx][ny] == 'X')
				continue;

			if (arr[nx][ny] == 'P')
				return 1;
			q.push({ nx,ny,len + 1 });
			vis[nx][ny] = pv;
		}
	}
	return 0;
}
vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;
	
	for (auto c : places) {
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				arr[i][j] = c[i][j];
		bool flag = 0;

		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (c[i][j] == 'P') {
					if (bfs(i, j) == 1) {
						flag = 1;
						break;
					}
				}
			}
			if (flag)
				break;
		}

		if (flag)
			answer.push_back(0);
		else
			answer.push_back(1);
	}
	return answer;
}
