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
using namespace std;
using ll = long long;


int r, c;

int xa, xb;
int ya, yb;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

queue<pair<int, int>> water;
int melt[1501][1501];
int par[1501][1501];
int p[590000];
int find(int x) {
	if (p[x]==x)
		return x;
	return p[x]=find(p[x]);
}
void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	p[b] = a;
}
void make(int a, int b, int cc) {
	queue<pair<int, int>> q;
	q.push({ a,b });
	par[a][b] = cc;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
		
			if (nx < 0 || nx >= r || ny < 0 || ny >= c) 
				continue;
			
			if (melt[nx][ny] == -1) 
				continue;
			
			
		
			if (par[nx][ny] == 0) {
				par[nx][ny] = cc;
				q.push({ nx,ny });
			}
		
		}

	}
}
int main() {
	ios::sync_with_stdio(0),cin.tie(0);

	cin >> r >> c;
	string s;
	xa = -1;
	for (int i = 0; i < r; i++) {
		cin >> s;
		for (int j = 0; j < c; j++) {
			if (s[j] == 'X')
				melt[i][j] = -1;
			else {
				melt[i][j] = 0;
				water.push({ i,j });
			}
			if (s[j] == 'L') {
				if (xa == -1) {
					xa = i;
					ya = j;
				}
				else {
					xb = i;
					yb = j;
				}
			}
		}
	}

	int gr = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (melt[i][j]==0&&par[i][j] == 0) {
				gr++;
				p[gr] = gr;
				make(i,j,gr);
			}
		}
	}

	



	
		while (!water.empty()) {
			int x = water.front().first;
			int y = water.front().second;
			int ti = melt[x][y];
			water.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || nx >= r || ny < 0 || ny >= c)
					continue;
			
				if (par[nx][ny] == 0) {
					par[nx][ny] = par[x][y];
					melt[nx][ny] = ti + 1;
					water.push({ nx,ny });
				}
				else {
					uni(par[x][y], par[nx][ny]);
					if (find(par[xa][ya]) == find(par[xb][yb])) {
						cout << max(melt[nx][ny], melt[x][y]);
						return 0;
					}
				}
			}
		}
		
	
	
	
}