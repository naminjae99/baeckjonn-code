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
#include<iomanip>
using namespace std;
using ll = long long;


int t, n, m;
vector<pair<int, int>>ed[5005];
int s, e;

int arr[101][101];

pair<int, int>st;
pair<int, int>en;

struct f {
	int x, y, cnt;
	bool operator<(const f& o)const {
		return cnt > o.cnt;
	}
};
int d[3][105][105];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> n >> m;
		st.first = -1;
		memset(arr, 0, sizeof(arr));
		for (int i = 1; i <= n; i++) {
			string s;
			cin >> s;
			for (int j = 1; j <=m; j++) {
				if (s[j-1] == '*')
					arr[i][j] = -1;
				else if (s[j-1] == '#')
					arr[i][j] = 1;
				else if (s[j-1] == '$') {
					if (st.first == -1)
						st = { i,j };
					else
						en = { i,j };
				}
			}
		}

		
		priority_queue<f>q;
		for (int k = 0; k < 3; k++) {
			for (int i = 0; i <= n + 1; i++) {
				for (int j = 0; j <= m + 1; j++) {
					d[k][i][j] = 1e9;
				}
			}
		}
		d[0][0][0] = 0;
		q.push({ 0,0,0 });
		while (!q.empty()) {
			int x = q.top().x;
			int y = q.top().y;
			int cnt = q.top().cnt;
			q.pop();
			if (d[0][x][y] != cnt)
				continue;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<0 || nx>n + 1 || ny<0 || ny>m + 1)
					continue;
			
				if (arr[nx][ny] == -1)
					continue;
				if (arr[nx][ny] == 0 && d[0][nx][ny] > cnt) {
					d[0][nx][ny] = cnt;
					q.push({nx, ny, d[0][nx][ny]});
				}
				if (arr[nx][ny] == 1 && d[0][nx][ny] > cnt + 1) {
					d[0][nx][ny] = cnt + 1;
					q.push({ nx, ny, d[0][nx][ny] });
				}
			}
		}

		d[1][st.first][st.second] = 0;
		q.push({st.first,st.second,0 });
		while (!q.empty()) {
			int x = q.top().x;
			int y = q.top().y;
			int cnt = q.top().cnt;
			q.pop();
			if (d[1][x][y] != cnt)
				continue;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<0 || nx>n + 1 || ny<0 || ny>m + 1)
					continue;

				if (arr[nx][ny] == -1)
					continue;
				if (arr[nx][ny] == 0 && d[1][nx][ny] > cnt) {
					d[1][nx][ny] = cnt;
					q.push({ nx, ny, d[1][nx][ny] });
				}
				if (arr[nx][ny] == 1 && d[1][nx][ny] > cnt + 1) {
					d[1][nx][ny] = cnt + 1;
					q.push({ nx, ny, d[1][nx][ny] });
				}
			}
		}
	
		d[2][en.first][en.second] = 0;
		q.push({ en.first,en.second,0 });
		while (!q.empty()) {
			int x = q.top().x;
			int y = q.top().y;
			int cnt = q.top().cnt;
			q.pop();
			if (d[2][x][y] != cnt)
				continue;

			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx<0 || nx>n + 1 || ny<0 || ny>m + 1)
					continue;

				if (arr[nx][ny] == -1)
					continue;
				if (arr[nx][ny] == 0 && d[2][nx][ny] > cnt) {
					d[2][nx][ny] = cnt;
					q.push({ nx, ny, d[2][nx][ny] });
				}
				if (arr[nx][ny] == 1 && d[2][nx][ny] > cnt + 1) {
					d[2][nx][ny] = cnt + 1;
					q.push({ nx, ny, d[2][nx][ny] });
				}
			}
		}
		/*
		for (int k = 0; k < 3; k++) {
			for (int i = 0; i <= n + 1; i++) {
				for (int j = 0; j <= m + 1; j++) {
					if (d[k][i][j] == 1e9||arr[i][j]==-1)
						cout << setw(2) << 'x'<<" ";
					else
						cout << setw(2)<<d[k][i][j] << " ";
				}
				cout << "\n";
			}
			cout << "\n\n\n";
		}
		*/
		ll re = 1e18;
		for (int i = 0; i <= n + 1; i++) {
			for (int j = 0; j <= m + 1; j++) {
				if (arr[i][j] == -1)
					continue;
				ll sum = (ll)d[0][i][j] + (ll)d[1][i][j] + (ll)d[2][i][j];
				if (arr[i][j]==1)
					sum -= 2;
				re = min(re, sum);
				
			}
		}
		cout << re<<"\n";
		

	}
}
