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

int dx[4] = { 0,1,0,-1};
int dy[4] = { -1,0,1,0 };


int n, m, t,k,ret;
int arr[505][505];

int ddx[4][10] = { {-2,-1,-1,-1,0,1,1,1,2,0},{0,1,0,-1,2,1,0,-1,0,1}
,{2,1,1,1,0,-1,-1,-1,-2,0},{0,-1,0,1,-2,-1,0,1,0,-1} };
int ddy[4][10] = { {0,-1,0,1,-2,-1,0,1,0,-1},{-2,-1,-1,-1,0,1,1,1,2,0}
,{0,1,0,-1,2,1,0,-1,0,1},{2,1,1,1,0,-1,-1,-1,-2,0} };
int percent[9] = { 2,10,7,1,5,10,7,1,2 };

int cx, cy,cd;
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	cx = cy = n / 2;
}
void solve() {
	int dis = 1;
	int cnt = 0;
	int one = 0;

	int z = 10;
	while (1) {
		if (cx == 0 && cy == 0)
			break;
		//dis 만큼 이동
		cx += dx[cd];
		cy += dy[cd];
		
		//cout <<"현재"<< cx << ", " << cy << "\n";
		int cur = arr[cx][cy];
		int total = 0;

		for (int i = 0; i < 9; i++) {
			int nx = cx + ddx[cd][i];
			int ny = cy + ddy[cd][i];
			int add = cur * percent[i] / 100;
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
				ret += add;
				total += add;
			}
			else {
				arr[nx][ny] += add;
				total += add;
			}
		}
		int nx = cx + ddx[cd][9];
		int ny = cy + ddy[cd][9];
		if (!(nx < 0 || nx >= n || ny < 0 || ny >= n))
			arr[nx][ny] += cur - total;
		else
			ret += cur - total;
		arr[cx][cy] = 0;
			
		cnt++;
		if (cnt == dis) {
			one++;
			cd = (cd + 1) % 4;
			cnt = 0;
			if (dis!=n-1&&one == 2) {
				one=cnt = 0;
				dis++;
			}
		}

	
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	input();
	solve();
	cout << ret;
	return 0;
}