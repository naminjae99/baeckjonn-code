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


int dx[8] = { -1,1,0,0,-1,-1,1,1 };
int dy[8] = { 0,0,-1,1,-1,1,-1,1 };

int n,m, ret, t, k;
int arr[1005][1005];
queue<int> q,qq;
int tmp[1005][1005];
int vis[1005][1005];
int pv;

void bfs() {
	
	

	while (!q.empty()) {
		int x = q.front() / n;
		int y = q.front() % n;
		q.pop();
		arr[x][y] = 0;
		for (int z = 0; z < 8; z++) {
			int nx = x + dx[z];
			int ny = y + dy[z];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (arr[nx][ny] == 0 || arr[nx][ny] == 9)
				continue;
			tmp[nx][ny]++;
		}
	}	
	
	++pv;

	int qs = qq.size();
	while (qs--) {
		int x = qq.front() / n;
		int y = qq.front() % n;
		qq.pop();

		//삭제된거 주위로 확인
		int cnt = 0;
		for (int z = 0; z < 8; z++) {
			int nx = x + dx[z];
			int ny = y + dy[z];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (arr[nx][ny] == 0 || arr[nx][ny] == 9||vis[nx][ny]==pv)
				continue;
			if (tmp[nx][ny] >= arr[nx][ny]) {
				vis[nx][ny] = pv;
				q.push(nx*n + ny);
				qq.push(nx*n + ny);
			}
			
		}
		
	}



}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] != '.')
				arr[i][j] = s[j]-'0';
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 || arr[i][j] == 9)
				continue;

			int cnt = 0;
			for (int z = 0; z < 8; z++) {
				int nx = i + dx[z];
				int ny = j + dy[z];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;
				if (arr[nx][ny] == 0)
					cnt++;
			}
			tmp[i][j] = cnt;
			if (cnt >= arr[i][j]) {
				q.push(i*n + j);
				qq.push(i*n + j);
			}
		}
	}





	while (1) {
		if (!q.empty()) {
			ret++;
			bfs();
		}
		else
			break;
	}



	cout << ret;
}



int main() {
	fastio
		input();

}