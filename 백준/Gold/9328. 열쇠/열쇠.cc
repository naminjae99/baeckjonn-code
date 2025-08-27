#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<string.h>
#include<set>
#include<iomanip>
#include<unordered_set>

using namespace std;
int n, t, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

char arr[105][105];
bool key[26];
bool vis[105][105];
int re;
bool fd[105][105];

void init() {
	re = 0;
	memset(vis, 0, sizeof(vis));
	memset(key, 0, sizeof(key));
	memset(fd, 0, sizeof(fd));
}
void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= m; j++) {
			arr[i][j] = s[j - 1];
		}
	}
	string s;
	cin >> s;
	if (s == "0")
		return;
	for (auto c : s) {
		key[c - 'a'] = 1;
	}
}

queue<pair<int, int>> q;
void fq() {
	for (int i = 1; i <= m; i++) {
		q.push({ 0,i });
		vis[0][i] = 1;
		q.push({ n + 1,i });
		vis[n + 1][i] = 1;
	}
	for (int i = 1; i <= n; i++) {
		q.push({ i,0 });
		vis[i][0] = 1;
		q.push({ i,m + 1 });
		vis[i][m + 1] = 1;
	}
}


void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || nx>n || ny<0 || ny>m)
				continue;
			if (arr[nx][ny] == '*')
				continue;
			if (vis[nx][ny])
				continue;
			if (arr[nx][ny] == '.') {
				vis[nx][ny] = 1;
				q.push({ nx,ny });
			}
			else if (arr[nx][ny] == '$') {
				vis[nx][ny] = 1;
				q.push({ nx,ny });
				fd[nx][ny] = 1;
			}
			else if (arr[nx][ny] >= 'A'&&arr[nx][ny] <= 'Z') {
				if (key[arr[nx][ny] - 'A']) {
					vis[nx][ny] = 1;
					q.push({ nx,ny });
				}
			}
			else {
				//새 키를 찾으면 다시시작
				if (key[arr[nx][ny] - 'a'] == 0) {
					memset(vis, 0, sizeof(vis));
					key[arr[nx][ny] - 'a'] = 1;
					q = {};
					fq();
					bfs();
					return;
				}
				vis[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}
void pr() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << vis[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		init();
		input();
		
		q = {};
		fq();

		bfs();
	

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (fd[i][j])
					re++;
			}
		}

		cout << re << "\n";
	}
}