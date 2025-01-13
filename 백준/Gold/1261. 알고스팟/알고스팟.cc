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
int arr[101][101];
int n, m;
int wall;
int vis[101][101];
struct info {
	int x, y, w;
};
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int re = 987654321;
struct cmp{
	bool operator()(info a, info b) {
		return a.w > b.w;
	}

}; 
void f() {
	
	priority_queue <info,vector<info>,cmp> q;
	q.push({ 0,0,0 });
	vis[0][0] = 1;

	while (!q.empty()) {
		int x = q.top().x;
		int y = q.top().y;
		int w = q.top().w;
		q.pop();
	//	cout << x << ", " << y << "에 " << w << "개의 벽부수고 도착\n";

		if (x == n - 1 && y == m - 1) {
			re = min(re, w);
		
			continue;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (arr[nx][ny] == 1) {
				if (vis[nx][ny] == 0) {
					q.push({ nx,ny,w + 1 });
					vis[nx][ny] =1;
				}
			
			}
			else {
				if (vis[nx][ny] == 0) {
					q.push({ nx,ny,w});
					vis[nx][ny]=  1;
				}
				
			}
		
		}

	}
}
int main() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j]-'0';
			if (arr[i][j] == 1)
				wall++;
		}
	}

	f();
	cout << re;
}