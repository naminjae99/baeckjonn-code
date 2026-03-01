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


int dx[9] = {-2,-2,-1,-1,1,1,2,2};
int dy[9] = {-1,1,-2,2,-2,2,-1,1};

int m, ret, t, k, Q, n;


int arr[15][15];
int idx;
int vis[105][15][15];
int kk[105];

struct f {
	int x, y;

};


void bfs(int num, int a, int b) {
	memset(vis[num], -1, sizeof(vis[num]));
	queue<f>q;
	q.push({ a,b});
	vis[num][a][b] = 0;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (vis[num][nx][ny] != -1)
				continue;
			q.push({ nx,ny });
			vis[num][nx][ny] = vis[num][x][y] + 1;
			
		}
	}
}



void input(){
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] !='.'){
				kk[idx] = s[j] - '0';
				bfs(idx++,i, j);
			}
		}
	}

	if (idx == 1) {
		cout << 0;
		return;
	}


	// 모든 말들이 같은값을 가지는 vis중에 가장 작은값 찾기
	ret = 1e9;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			
			int sum = 0;
			for (int num = 0; num < idx; num++) {
				if (vis[num][i][j] == -1) {
					sum = 1e9;
					break;
				}
				sum += (vis[num][i][j]+kk[num]-1)/kk[num];
			}
			ret = min(sum, ret);
		}
	}
	if (ret == 1e9)
		cout << -1;
	else
		cout << ret;
		
}



int main() {
	fastio
		input();

}