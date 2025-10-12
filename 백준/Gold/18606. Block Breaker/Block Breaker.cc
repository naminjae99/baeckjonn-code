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

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, ret, k, t, Q, p;

int arr[2005][2005];


void input() {

}

bool check(int x, int y) {
	if (((arr[x - 1][y] || arr[x + 1][y]) && (arr[x][y - 1] || arr[x][y + 1])))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void solve() {
	cin >> t;

	while (t--){
		cin >> n >> m >> k;
		memset(arr, 0, sizeof(arr));
		//0이면 블럭있음

		while (k--) {
			int x, y;
			cin >> x >> y;
			if (arr[x][y]) {
				cout << 0 << "\n";
				continue;
			}



			arr[x][y] = 1;
			int sum = 1;

			queue<pair<int, int>>q;
			q.push({ x,y });

			while (!q.empty()) {
				x = q.front().first;
				y = q.front().second;
				q.pop();

				for (int i = 0; i < 4; i++) {
					int nx = x + dx[i];
					int ny = y + dy[i];
					if (arr[nx][ny])
						continue;
					if (check(nx, ny)) {
						arr[nx][ny] = 1;
						sum++;
						q.push({ nx,ny });
					}
				}
			}

			cout << sum << "\n";

			
		}
	}
}
int main() {
	fastio;
	input();
	solve();

}


