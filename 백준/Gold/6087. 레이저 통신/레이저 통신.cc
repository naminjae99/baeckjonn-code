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
#include<map>
using namespace std;
using ll = long long;

int n, m, k, t;

struct f {
	int x,y, dir,cnt;
	bool operator<(const f& o)const {
		return cnt > o.cnt;
	}
};
priority_queue<f> q;
int d[105][105][4];
int arr[105][105];

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int xx1, yy1, xx2, yy2;

bool bound(int x, int y) {
	return (x < 0 || x >= n || y < 0 || y >= m);
}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	xx1 = -1;

	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == '.')
				arr[i][j] = 0;
			else if (s[j] == '*')
				arr[i][j] = 1;
			else {
				if (xx1 == -1) {
					xx1 = i, yy1 = j;
				}
				else
					xx2 = i, yy2 = j;
				arr[i][j] = 0;
			}
			for (int z = 0; z < 4; z++)
				d[i][j][z] = 1e9;
		}
		
	}
	

	for (int i = 0; i < 4; i++) {
		d[xx1][yy1][i] = 0;
		int nx = xx1 + dx[i];
		int ny = yy1 + dy[i];
		if (!bound(nx, ny) && arr[nx][ny] == 0) {
			d[nx][ny][i] = 0;
			q.push({ nx,ny,i,0 });
		}
	}
	int re = 1e9;
	while (!q.empty()) {
		int x = q.top().x;
		int y = q.top().y;
		int dir = q.top().dir;
		int cnt = q.top().cnt;
		q.pop();

		
		if (d[x][y][dir] < cnt)
			continue;
		if (x == xx2 && y == yy2) {
			cout << cnt;
			break;
		}
		//cout << x << ", " << y << "에서 " << dir << "방향가지고 cnt: " << cnt << "\n";
	
		//가는방향이 가능하면 그냥 cnt로
		//돌려서 가능하면 cnt+1

		//막다른길 -> 거울이용
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (i == dir) {
				//nx ny기준으로 이동가능한지
				if (!bound(nx, ny) && arr[nx][ny] == 0 && d[nx][ny][i] > cnt) {
					d[nx][ny][i] = cnt;
					q.push({ nx,ny,i,cnt });
					//cout << "같은방향" << nx << ", " << ny << "," << i << ", " << cnt << "추가\n";
				}
				continue;
			}
			
			
			//방향바꾸는거 자체가 비용듬
			if (bound(nx, ny))
				continue;
			if (arr[nx][ny])
				continue;
			if (d[nx][ny][i] > cnt + 1) {
				d[nx][ny][i] = cnt + 1;
				q.push({ nx,ny,i,cnt + 1 });
				//cout << "다른방향" << nx << ", " << ny <<","<<i<<", "<<cnt+1<<"추가\n";
			}
		}
	//	cout << "\n\n\n";
		

	}
	//cout << re << "\n";
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0)
				cout << arr[i][j] << " ";
			else
				cout << "  ";
		}
		cout << "\n";
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++){
			if (d[i][j] == 1e9)
				cout << 'X'<<" ";
			else
			cout<<d[i][j]<<" ";
		}
		cout<<"\n";
	}
	*/
}
