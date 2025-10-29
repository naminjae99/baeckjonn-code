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
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;

int dx[4] = { 1,0,-1,0};
int dy[4] = {0,-1,0,1 };
char dxdy[4] = { 'S','W','N','E' };
int n, m, ret, k, t, Q;


int arr[105][105];
ll l;



struct f {
	int x, y, d;
};
ll vis[105][105][4];
f st;



void solve() {
	queue<f> q;
	q.push(st);
	memset(vis, -1, sizeof(vis));

	vis[st.x][st.y][st.d] = 0;

	int nstx, nsty,nstd;
	ll pos = 0;
	ll per = 0;


	while (!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int d = q.front().d;
		q.pop();
		
	
		if (vis[x][y][d] == l) {
			cout << x + 1 << " " << y + 1 << " " << dxdy[d] << "\n";
			return;
		}

		int nd = d;
		int nx, ny;
		while (1) {
			nx = x + dx[nd];
			ny = y + dy[nd];
			
			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				nd = (nd + 1) % 4;
				continue;
			}
			if (arr[nx][ny]) {
				nd = (nd + 1) % 4;
				continue;
			}
			if (vis[nx][ny][nd] != -1) {
				pos = vis[nx][ny][nd];
				per = vis[x][y][d] + 1 - pos;
				l -= pos;
				l = l % per;
				
				memset(vis, -1, sizeof(vis));
				vis[nx][ny][nd] = 0;
				q.push({ nx,ny,nd });
			}
			else {
				vis[nx][ny][nd] = vis[x][y][d] + 1;
				q.push({ nx,ny,nd });
			}

			break;
		}
	
	}
	

}

void input() {
	while (1) {
		cin >> n >> m >> l;
		if (!n && !m && !l)
			return;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				if (s[j] == 'E') {
					st = { i,j,3}; arr[i][j] = 0;
				}
				else if (s[j] == 'W'){
						st = { i,j,1}; arr[i][j] = 0;
			}
				else if (s[j] == 'N'){
					st = { i,j,2}; arr[i][j] = 0;
				}
				else if (s[j] == 'S'){
					st = { i,j,0 }; arr[i][j] = 0;
				}
				else if (s[j] == '.')
					arr[i][j] = 0;
				else
					arr[i][j] = 1;
			}
		}
		/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}

		cout << "\n\n";*/

		solve();

	}
}


int main() {
	fastio;

	input();
	
	
	return 0;
}



