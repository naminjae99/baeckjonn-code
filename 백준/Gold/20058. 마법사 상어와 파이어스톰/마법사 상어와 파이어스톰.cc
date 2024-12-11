#include <iostream>
#include <queue>
#include <memory.h>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;


int n, q;

int arr[65][65];
int vis[65][65];
int result;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int na[65][65];

int len;

void turn(int x, int y, int s) {
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			na[j][s - 1 - i] = arr[x + i][y + j];
		}
	}

	for (int i = 0; i < s; i++) {
		for (int j = 0; j < s; j++) {
			arr[x + i][y + j] = na[i][j];
		}
	}

}

int check(int a, int b) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int na = a + dx[i];
		int nb = b + dy[i];
		if (na < 0 || na >= len || nb < 0 || nb >= len)
			continue;
		if (arr[na][nb] <= 0)
			continue;
		cnt++;
	}

	if (cnt >=3)
		return 1;
	else 
		return 0;
}

int bfs(int a, int b) {

	queue <pair<int, int>> qq;
	qq.push({ a,b });
	vis[a][b] = 1;
	int cnt = 1;

	while (!qq.empty()) {
		int x = qq.front().first;
		int y = qq.front().second;
		qq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= len || ny < 0 || ny >= len)
				continue;
			if (arr[nx][ny] <= 0 || vis[nx][ny] == 1)
				continue;
			cnt++;
			qq.push({ nx,ny });
			vis[nx][ny] = 1;
		}
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cout.tie(0);

	cin >> n >> q;
	len = pow(2, n);
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			cin >> arr[i][j];
		}
	}

	queue <int> v;

	for (int i = 0; i < q; i++) {
		int a;
		cin >> a;
		v.push(a);
	}



	while (q--) {

		int s = v.front();
			v.pop();
			s = pow(2, s);

		for (int i = 0; i < len; i += s) {
			for (int j = 0; j < len; j +=s) {
				turn(i, j, s);
			}
		}
		


		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (!arr[i][j])
					continue;

					if (!check(i, j)) {
						vis[i][j] = -1;
					}
				
			}
		}
		
		

		for (int i = 0; i < len; i++) {
			for (int j = 0; j < len; j++) {
				if (vis[i][j] == -1) {
					arr[i][j]--;
					vis[i][j] = 0;
				}
				
			}
		}
		
	}

	int sum = 0;

	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len; j++) {
			if (arr[i][j] > 0)
				sum += arr[i][j];
		}
	}
	

	for (int i = 0; i < len; i++) {
		for (int k = 0; k < len; k++) {
			if (vis[i][k] == 0 && arr[i][k] > 0) {
				result = max(result, bfs(i, k));
			}
		}
	}



	cout << sum << "\n" << result;

}