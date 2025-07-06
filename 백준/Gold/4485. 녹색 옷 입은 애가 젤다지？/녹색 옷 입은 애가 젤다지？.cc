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


int t, n, m;
int d[126][126];
int arr[126][126];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct f {
	int x, y, cost;
	bool operator<(const f& o)const {
		return cost > o.cost;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tc = 1;
	while (1) {
		cin >> n;
		if (n == 0)
			break;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
				d[i][j] = 1e9;
			}
		}

		priority_queue<f>q;
		q.push({ 0,0,arr[0][0] });
		d[0][0] = arr[0][0];

		while (!q.empty()) {
			int x = q.top().x;
			int y = q.top().y;
			int cost = q.top().cost;
			q.pop();

			
			if (d[x][y] != cost)
				continue;
			if (x == n - 1 && y == n - 1)
				break;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;
				if (d[nx][ny] > cost + arr[nx][ny]) {
					d[nx][ny] = cost + arr[nx][ny];
					q.push({ nx ,ny,d[nx][ny] });
				}
			}
		}
		cout <<"Problem "<<tc++<<": "<< d[n - 1][n - 1] << "\n";
	}
}
