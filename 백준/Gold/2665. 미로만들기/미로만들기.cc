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

int n, m, k,t;
bool arr[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1, };

int d[51][51];

struct f {
	int x,y, cnt;
	bool operator<(const f& a)const {
		return cnt > a.cnt;
	}
};
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < n; j++) {
			arr[i][j] = s[j] - '0';

			d[i][j] = 1e9;

		}
	}
	priority_queue<f>q;
	q.push({ 0,0,0 });
	d[0][0] = 0;

	while (!q.empty()) {
		int x = q.top().x;
		int y = q.top().y;
		int cnt = q.top().cnt;
		q.pop();
		if (d[x][y] < cnt)
			continue;
		if (x == n - 1 && y == n - 1) {
			cout << cnt;
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (arr[nx][ny]) {
				if (d[nx][ny] > cnt) {
					d[nx][ny] = cnt;
					q.push({ nx,ny,cnt });
				}
			}
			else {
				if (d[nx][ny] > cnt + 1) {
					d[nx][ny] = cnt + 1;
					q.push({ nx,ny,cnt + 1 });
				}
			}
		}
	}
}
