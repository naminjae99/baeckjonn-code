#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>

using namespace std;

struct cc {
	int x;
	int y;
	int s;
	int d;
};

int n, m;
int  arr[10][10];
int  na[10][10];


int re;
int cnt;

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

//종류 방향 x y
vector <cc> v;


void check(int grid[][10], int x, int y, int dir) {
	int nx = x, ny = y;
	while (true) {
		nx += dx[dir];
		ny += dy[dir];
		if (nx < 0 || nx >= n || ny < 0 || ny >= m || grid[nx][ny] == 6)
			break;
		if (grid[nx][ny] == 0)
			grid[nx][ny] = -1;
	}
}

void dfs() {
	memcpy(na, arr, sizeof(arr));

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].x;
		int y = v[i].y;
		int state = v[i].s;
		int dir = v[i].d;

		if (state == 1) {
			check(na, x, y, dir);
		}
		if (state == 2) {
			check(na, x, y, dir);
			check(na, x, y, (dir+2)%4);
		}
		if (state == 3) {
			check(na, x, y, dir);
			check(na, x, y, (dir + 3) % 4);
		}
		if (state == 4) {
			check(na, x, y, dir);
			check(na, x, y, (dir + 3) % 4);
			check(na, x, y, (dir + 2) % 4);
		}
		if (state == 5) {
			check(na, x, y, dir);
			check(na, x, y, (dir + 1) % 4);
			check(na, x, y, (dir + 3) % 4);
			check(na, x, y, (dir + 2) % 4);
		}
	}


	int tmp = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (na[i][j] ==0){
				tmp += 1;
			}
		}
	}
	re = min(re, tmp);
	
	return;
}

void f(int dep) {
	if (dep == v.size()) {
		int flag = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].s == 2 && v[i].d >= 2)
				flag = 1;
			if (v[i].s == 5 && v[i].d >= 1)
				flag = 1;
		}
		if (flag == 1)
			return;
		else {
			dfs();
			return;
		}
		
	}

	for (int i = 0; i < 4; i++) {
		
		v[dep].d = i;
		
		f(dep + 1);
	}

}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			arr[i][j] = a;
			if (arr[i][j] != 0 && arr[i][j] != 6) {
				v.push_back({ i,j,a,0 });
			}
		}


	}
	re = m * n;
	f(0);

	cout << re;
}