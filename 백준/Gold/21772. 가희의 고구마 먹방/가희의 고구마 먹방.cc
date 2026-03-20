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
int n,m, ret, t, k, Q, L;

int dx[9] = { 0,1,0,-1,0};
int dy[9] = { 1,0,-1,0,0 };
char arr[105][105];
pair<int, int> st;
int vis[105][105];

void dfs(int x, int y, int dep,int cnt) {
	if (k - dep <= ret - cnt) {
		return;
	}
	if (dep == k ) {
		ret = max(cnt, ret);
		return;
	}

	for (int i = 0; i < 5; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		if (arr[nx][ny] == '#')
			continue;
		if (arr[nx][ny] == 'S') {
			arr[nx][ny] = '.';
			dfs(nx, ny, dep + 1, cnt + 1);
			arr[nx][ny] = 'S';
		}
		else {
			dfs(nx, ny, dep + 1, cnt);
		}
	}
}

void input() {
	cin >> n>>m>>k;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
			if (s[j] == 'G') {
				st = { i,j };
				arr[i][j] = '.';
			}
		}
	}
	dfs(st.first, st.second, 0,0);
	cout << ret;
}



void run() {


}


int main() {
	fastio
		input();
	run();

}
