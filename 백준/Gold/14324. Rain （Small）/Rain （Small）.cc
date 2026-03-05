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


int dx[9] = { 0,1,0,-1 };
int dy[9] = { 1,0,-1,0 };

int m, ret, t, k, Q, n;

int arr[15][15];
int d[15][15];
struct f {
	int x, y, h;
	bool operator<(const f& o)const {
		return h > o.h;
	}
};

void input() {
	cin >> t;

	for(int tc=1;tc<=t;tc++) {
		cin >> n >> m;
		ret = 0;
		priority_queue<f>q;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];

				// 테두리(가장자리)인 경우 큐에 삽입하고 방문 처리
				if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
					d[i][j] = arr[i][j];
					q.push({ i, j, arr[i][j] }); // 구조체 인자 3개(x, y, h) 모두 명시
				}
				else {
					d[i][j] = 1e9; // 내부 칸은 무한대로 초기화
				}
			}
		}
		
		while (!q.empty()) {
			int x = q.top().x;
			int y = q.top().y;
			int h = q.top().h;
			q.pop();
			if (d[x][y]!=h)
				continue;

	
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;
				int mx = max(arr[nx][ny], h);
				if (d[nx][ny] != 1e9&&d[nx][ny] <= mx)
					continue;
					q.push({ nx,ny,mx });
					d[nx][ny] = mx;
				

			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
			//	cout << d[i][j] << " ";
				ret += d[i][j] - arr[i][j];
			}
			//cout << "\n";
		}

		cout << "Case #" << tc << ": " << ret << "\n";
	}

}



int main() {
	fastio
		input();

}