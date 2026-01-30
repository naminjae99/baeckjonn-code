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

int n, m, ret;
char arr[1005][1005];
int vis[1005][1005];
int vvis[1005][1005];

pair<int, int> st, en;
vector<pair<int, int>> tmp;
void input() {
	cin >> n >> m;


	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j]=s[j];
			if (arr[i][j] == 'S')
				st = { i,j };
			else if (arr[i][j] == 'H')
				en = { i,j };
			else if (arr[i][j] == 'F')
				tmp.push_back({ i,j });
		}
	}
	memset(vis, -1, sizeof(vis));

	queue<pair<int, int>>q;
	vis[st.first][st.second] = 0;
	q.push(st);



	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
	
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (vis[nx][ny] != -1 || arr[nx][ny] == 'D')
				continue;
			q.push({ nx,ny });
			vis[nx][ny] = vis[x][y] + 1;
		}
	}
		

	memset(vvis, -1, sizeof(vvis));
	q = {};

		vvis[en.first][en.second] = 0;
		q.push(en);


	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();


		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (vvis[nx][ny] != -1 || arr[nx][ny] == 'D')
				continue;
			q.push({ nx,ny });
			vvis[nx][ny] = vvis[x][y] + 1;
		}
	}
	
	ret = 1e9;
	for (auto c : tmp) {
		if (vis[c.first][c.second] == -1 || vvis[c.first][c.second] == -1)
			continue;
		ret = min(ret, vis[c.first][c.second] + vvis[c.first][c.second]);
	}
	if (ret == 1e9)
		ret = -1;
	cout << ret;

}
int main() {
	fastio
		input();

}
