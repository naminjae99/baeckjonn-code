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
using namespace std;
using ll = long long;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0 };

int n, m, t, ret, h, k;

int arr[55][55];
int cpy[55][55];

int sx, sy;
void input() {
	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == -1)
				sx = i;
		}
	}
}

void solve() {
	while (t--) {
		memcpy(cpy, arr, sizeof(arr));

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int add = arr[i][j] / 5;
				if (add == 0)
					continue;
				for (int z = 0; z < 4; z++) {
					int nx = i + dx[z];
					int ny = j + dy[z];
					if (nx < 0 || nx >= n || ny < 0 || ny >= m)
						continue;
					if (arr[nx][ny] == -1)
						continue;
					cpy[i][j] -= add;
					cpy[nx][ny] += add;
				}
			}
		}
		memcpy(arr, cpy, sizeof(arr));

	/*
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}

		cout << "\n";*/

		for (int i = sx - 2; i > 0; i--) 
			arr[i][0] = arr[i - 1][0];
		for (int j = 0; j < m - 1; j++)
			arr[0][j] = arr[0][j + 1];
		for (int i = 0; i < sx - 1; i++)
			arr[i][m - 1] = arr[i + 1][m - 1];
		for (int j = m - 1; j > 1; j--)
			arr[sx - 1][j] = arr[sx - 1][j - 1];
		arr[sx - 1][1] = 0;

		
		for (int i = sx + 1; i <n-1; i++)
			arr[i][0] = arr[i + 1][0];
		for (int j = 0; j < m - 1; j++)
			arr[n-1][j] = arr[n-1][j + 1];
		for (int i = n-1; i >sx; i--)
			arr[i][m - 1] = arr[i - 1][m - 1];
		for (int j = m - 1; j > 1; j--)
			arr[sx][j] = arr[sx][j - 1];
		arr[sx][1] = 0;


		/*
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					cout << arr[i][j] << " ";
				}
				cout << "\n";
			}

			cout << "\n";*/
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ret += arr[i][j];
		}
	}
	ret += 2;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);



	/*
	cin >> t;
	for (int i = 1; i <= t; i++) {
		input();

	}*/
	
	input();
	solve();
	cout << ret;
}
