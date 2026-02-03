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

int n, m, ret, t;
int arr[51][51];
int pv;
int vis[51][51];
struct f {
	int x, y, z;
};
void bfs(int a, int b) {
	++pv;
	queue<f>qq;
	qq.push({a,b,0 });
	vis[a][b] = pv;

	while (!qq.empty()) {
		int x = qq.front().x;
		int y = qq.front().y;
		int z = qq.front().z;
		qq.pop();
		
		ret = max(ret, z);
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (vis[nx][ny]==pv || arr[nx][ny])
				continue;
			qq.push({ nx,ny,z+1 });
			vis[nx][ny] = pv;
		}
	}


}
void input() {
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'W')
				arr[i][j] = 1;
			
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j])
				continue;
			bfs(i, j);
		}
	}
	cout << ret;
}

int main() {
	fastio
		input();

}
