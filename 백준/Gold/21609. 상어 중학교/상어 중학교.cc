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

int dx[4] = { 0,1,0,-1 };
int dy[4] = { -1,0,1,0 };


int n, m, t, k, ret;

int arr[25][25];
int vis[25][25];
int v[25][25];

struct Node {
	int cnt,red, x, y;
};

Node del;


void input() {
	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

void bfs(int a, int b) {
	memset(v, 0, sizeof(v));

	queue<pair<int, int>> q;
	q.push({ a,b });
	vis[a][b] = 1;
	
	Node mx;

	mx.cnt=1, mx.red=0, mx.x=n, mx.y=n;

	int c = arr[a][b];

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (arr[x][y] == c) {
			if (mx.x == x) {
				if (mx.y > y)
					mx.y = y;
			}
			else if (mx.x > x) {
				mx.x = x, mx.y = y;
			}
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if (arr[nx][ny]==c&&vis[nx][ny]==0) {
				q.push({ nx,ny });
				vis[nx][ny] = 1;
				mx.cnt++;
			}
			else if(arr[nx][ny]==0&&v[nx][ny]==0) {
				q.push({ nx,ny });
				v[nx][ny] = 1;
				mx.red++;
				mx.cnt++;
			}
		}
	}
	/*cout << a << "," << b << "에서 찾은 그룹\n";
	cout << mx.cnt << ", " << mx.red << ", " << mx.x << ", " << mx.y << "\n\n";
	*/
	if (mx.cnt > 1) {
		if (del.cnt == mx.cnt) {
			if (del.red == mx.red) {
				if (del.x == mx.x) {
					if (del.y < mx.y)
						del = mx;
				}
				else if (del.x < mx.x)
					del = mx;
			}
			else if (del.red < mx.red)
				del = mx;
		}
		else if (del.cnt < mx.cnt)
			del = mx;
	}
}
void p() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == -2)
				cout << setw(2) << "x" << " ";
			else
			cout <<setw(2)<< arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

}
void boom() {
	queue<pair<int, int>> q;
	int a = del.x, b = del.y;
	q.push({ a,b});
	int c = arr[a][b];
	arr[a][b] = -2;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (arr[nx][ny] <= -1)
				continue;
			if (arr[nx][ny] == 0 || arr[nx][ny] == c) {
				q.push({ nx,ny });
				arr[nx][ny] = -2;
			}
		}
	}
}
void down() {
	for (int j = 0; j < n; j++) {
		for (int i = n - 1; i >= 0; i--) {
			if (arr[i][j] >= 0) {
				
				int idx = -1;
				for (int z = i + 1; z < n; z++) {
					if (arr[z][j] >= -1) {
						idx = z - 1;
						break;
					}
				}
				if (idx == -1) {
					if (i == n - 1)
						continue;
					arr[n-1][j] = arr[i][j];
					arr[i][j] = -2;
				}
				else if(idx!=i){
					arr[idx][j] = arr[i][j];
					arr[i][j] = -2;
				}

			
			}
		}
	}
}
int tmp[25][25];
void turn() {
	memcpy(tmp, arr, sizeof(tmp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[n - 1 - j][i] = tmp[i][j];
		}
	}
}
void solve() {	

	while (1) {
		
		del.cnt = 0, del.red = 0, del.x = -1, del.y = -1;
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] <= 0)
					continue;
				if (vis[i][j])
					continue;
				bfs(i, j);
			}
		}

		if (del.cnt == 0)
			break;
	
		ret += del.cnt*del.cnt;
		boom();
	
		down();
	
		turn();
	
		down();
	
	}
}

void calculator() {


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	solve();
	calculator();

	cout << ret;
	return 0;
}