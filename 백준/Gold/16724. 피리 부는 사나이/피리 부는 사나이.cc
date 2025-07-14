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

int n, m, k, t;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int arr[1005][1005];

int par[1000005];
bool vis[1000005];
int cnt;
int find(int x) {
	if (par[x] < 0)
		return x;
	return par[x] = find(par[x]);
}
bool uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return 0;
	cnt--;
	par[a] += par[b];
	par[b] = a;
	return 1;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n>>m ;
	cnt = m * n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			if (s[j] == 'U')
				arr[i][j] = 0;
			else if (s[j] == 'D')
				arr[i][j] = 1;
			else if (s[j] == 'L')
				arr[i][j] = 2;
			else
				arr[i][j] = 3;
		}
	}
	memset(par, -1, sizeof(par));


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i*m + j])
				continue;
		
//			cout << i << " , " << j << "시작\n";

			queue<pair<int, int>>q;
			q.push({ i,j });
			vis[i*m + j] = 1;

			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				
				int dir = arr[x][y];
				int nx = x + dx[dir];
				int ny = y + dy[dir];
				
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)
					continue;
				
				if (uni(x*m + y, nx*m + ny) == 0)
					continue;
				q.push({ nx,ny });
				vis[nx*m + ny] = 1;
			//	cout << x << ", " << y << "와 ";
			//	cout << nx <<" , "<< ny << "유니\n";
			}

		}
	}
	cout << cnt;
}
