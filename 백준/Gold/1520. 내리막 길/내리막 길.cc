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
#include<cfloat>
using namespace std;
using ll = long long;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int n, t, ret, h, k, m;
int arr[505][505];
int vis[505][505];

struct f {
	int x, y;
};
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	memset(vis, -1, sizeof(vis));
	vis[0][0] = 1;
}

int cal(int x, int y) {
	if (vis[x][y]!=-1)
		return vis[x][y];

	vis[x][y] = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m)
			continue;
		if (arr[nx][ny] > arr[x][y]) {
			vis[x][y] += cal(nx, ny);
		}
	}


	return vis[x][y];
}
void solve() {

	ret = cal(n - 1, m - 1);


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	input();
	solve();
	cout << ret;

}
