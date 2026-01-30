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

int arr[35][35];
int ori[35][35];
int vis[35][35];
bool bfs(int a, int b) {
	queue<pair<int, int>>q;
	q.push({ a,b });
	vis[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (vis[nx][ny])
				continue;
			if (arr[a][b] == arr[nx][ny]) {
				if (ori[a][b] != ori[nx][ny])
					return 0;
				q.push({ nx,ny });
				vis[nx][ny] = 1;
			}
		}
	}
	return 1;
}
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> arr[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> ori[i][j];

	bool flag = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j])
				continue;
			if (arr[i][j] != ori[i][j]) {
				if (flag) {
					cout << "NO";
					return;
				}
				else {
					bool f=bfs(i, j);
					if(f==0) {
						cout << "NO";
						return;
					}
						
					flag = 1;
				}
			}
		}
	}
	cout << "YES";
}
int main() {
	fastio
		input();

}
