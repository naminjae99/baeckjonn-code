#include <iostream>
#include <vector>
#include <queue>
#include<iomanip>
#include<string>
#include<memory.h>

using namespace std;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };
int n, m;
int arr[101][101];
int r, c;
int vis[101][101];
int h, w;
int grp[2][101][101];

void make(int a, int b, int bf) {
	int deep = -1;
	vector<pair<int, int>> info;

	queue<pair<int, int>> q;
	q.push({ a,b });

	vis[a][b] = 1;

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		info.push_back({ x,y });
		deep = max(deep, x);
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;
			if (vis[nx][ny])
				continue;
			if (arr[nx][ny] == 0)
				continue;
			q.push({ nx,ny });
			vis[nx][ny] = 1;

		}
	}
	for (auto i : info) {
		grp[bf][i.first][i.second] = deep;
	}
}
void pri() {
	cout << "arr\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 0)
				cout << '.';
			else
				cout << 'x';
		}
		cout << "\n";
	}
	cout << "\n\n";
}
void pri0() {
	cout << "grp0\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << grp[0][i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}
void pri1() {
	cout << "grp1\n";
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << grp[1][i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}
int main() {
	cin >> r >> c;
	for (int i = 0; i < r; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < c; j++) {
			if (s[j] == '.')
				arr[i][j] = 0;
			else
				arr[i][j] = 1;
		}
	}
	cin >> n;

	for (int tu = 0; tu < n; tu++) {
		cin >> h;

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				vis[i][j] = grp[0][i][j] = grp[1][i][j] = 0;
			}
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] == 0)
					continue;
				if (vis[i][j])
					continue;
				make(i, j, 0);
			}
		}
	//	pri0();
//
		h = r - h;

		w = -1;
		if (tu % 2 == 0) {
			for (int j = 0; j < c; j++) {
				if (arr[h][j]) {
					arr[h][j] = 0;
					w = j;
					break;
				}
			}
		}
		else {
			for (int j = c - 1; j >= 0; j--) {
				if (arr[h][j]) {
					arr[h][j] = 0;
					w = j;
					break;
				}
			}
		}
		if (w == -1)
			continue;

		memset(vis, 0, sizeof(vis));

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (arr[i][j] == 0)
					continue;
				if (vis[i][j])
					continue;
				make(i, j, 1);
			}
		}
		//pri1();

		vector<pair<int, int>> tmp;
		for (int j = 0; j < c; j++) {
			for (int i = r - 1; i >= 0; i--) {
				if (grp[1][i][j] == 0)
					continue;
				if (grp[0][i][j] != grp[1][i][j]) {
					tmp.push_back({ i,j });
				}

			}
		}
		int mn = r + 1;
		for (auto i : tmp) {
			int x = i.first;
			int y = i.second;
			int dis = 0;
		
			while (1) {
				if (x + dis + 1 >= r) {
					break;
				}
				if (grp[1][x + dis + 1][y] == grp[1][x][y]) {
					dis++;
					continue;
				}
				else {
					if (arr[x + dis + 1][y] == 1) {
						break;
					}
				}
				dis++;
			}
			//cout << x << " , " << y << "에서는 " << dis << "만큼 내력가기가능\n";
			
			mn = min(mn, dis);
		}
		if (mn == r + 1)
			continue;
		//cout << "결론 :" << mn << "만큼 이동가능\n";
		
		//grp가 다른점들을 mn만큼 내리기
		for (int j = 0; j < c; j++) {
			for (int i = r - 1; i >= 0; i--) {
				if (grp[1][i][j] == 0)
					continue;
				if (grp[0][i][j] != grp[1][i][j]) {
					arr[i + mn][j] = arr[i][j];
					arr[i][j] = 0;
				}
			}
		}




	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 0)
				cout << '.';
			else
				cout << 'x';
		}
		cout << "\n";
	}

}