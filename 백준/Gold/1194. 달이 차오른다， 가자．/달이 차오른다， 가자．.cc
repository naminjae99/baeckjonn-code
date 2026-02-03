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


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m, ret, t;
char arr[51][51];
pair<int, int> st;
int vis[51][51][65];

struct ff {
	int x, y, z,k;
};
void bfs() {


	queue<ff>q;
	q.push( {st.first, st.second, 0, 0 });
	vis[st.first][st.second][0] = 1;

	while (!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		int z = q.front().z;
		int k = q.front().k;
		q.pop();
	//	cout << x << "," << y << "를 " << z << "시간에 방문할떄: " << (k && 1) << ", "<< (k&(1 << 1)) << ", " << (k&(1 << 2)) << ", " << (k&(1 << 3)) << ", " << (k&(1 << 4)) << ", " << (k&(1 << 5))<<"\n";
		
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (vis[nx][ny][k] || arr[nx][ny] == '#')
				continue;
			if (arr[nx][ny] == '.') {
				q.push({ nx,ny,z+1,k });
				vis[nx][ny][k] = 1;
			}
			else if (arr[nx][ny] == '1') {
				ret = z+1;
				return;
			}
			else if (arr[nx][ny] >= 'A'&&arr[nx][ny] <= 'F') {
				if ( (k& (1<<(arr[nx][ny]-'A')))  !=0) {
					q.push({ nx,ny,z + 1,k });
					vis[nx][ny][k] = 1;
				}
			}
			else if (arr[nx][ny] >= 'a'&&arr[nx][ny] <= 'f'){
				if ( (k& (1<<(arr[nx][ny]-'a'))) ==0) {
					int nk = k + (1 << (arr[nx][ny] - 'a')) ;
					vis[nx][ny][nk] = 1;
					q.push({ nx,ny,z + 1,nk });
				}
				else {
					vis[nx][ny][k] = 1;
					q.push({ nx,ny,z + 1,k });
				}
			}
		}
	}


}
void input() {
	ret = 1e9;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j++) {
			arr[i][j] = s[j];
			if (arr[i][j] == '0') {
				st = { i,j };
				arr[i][j] = '.';
			}
		}
	}

	bfs();
	
	if (ret == 1e9)
		ret = -1;
	cout << ret;

}

int main() {
	fastio


		input();

}
