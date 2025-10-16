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
int n, m, ret, k, t, Q;

int arr[1005][1005];
bool vis[1005][1005];
int gr=2;
int gr_cnt[500005];

int qx[1000005];
int qy[1000005];
int fr, ba;

void bfs(int a, int b) {
	vis[a][b] = 1;
	fr = ba = 0;
	qx[ba] = a;
	qy[ba++] = b;
	arr[a][b] = gr;

	int cnt = 1;

	while (fr<ba) {
		int x = qx[fr];
		int y = qy[fr++];
	
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (vis[nx][ny]!=0)
				continue;
			if (arr[nx][ny])
				continue;
			qx[ba] = nx;
			qy[ba++] = ny;
			vis[nx][ny] = 1;
			arr[nx][ny] =gr;
			cnt++;
		}
	}
	gr_cnt[gr] = cnt%10;
	gr++;
}
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j] - '0';

		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]==0)
				bfs(i, j);
		}
	}
	
	unordered_set<int> tmp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] >=2)
				cout << 0;
			else {
				int re = 1;
				tmp.clear();
				for (int z = 0; z < 4; z++) {
					int nx = i + dx[z];
					int ny = j + dy[z];
					if (nx < 0 || ny < 0 || nx >= n || ny >= m)
						continue;
					tmp.insert(arr[nx][ny]);
				}
				for (auto c : tmp) {
					re += gr_cnt[c];
				}

				cout<<re%10;
			}
		}
		cout << "\n";
	}
}
void solve() {
	
}
int main() {
	fastio;
	input();
	solve();

}




