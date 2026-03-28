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
int n, m, ret, t, k, Q, L, h,w;

int dx[9] = { -1,0,1,0,-1,-1,1,1 };
int dy[9] = { 0,1,0,-1,-1,1,-1,1 };
int arr[1005][1005];
int vis[1005][1005];
int pv;
 bool out(int x, int y) {
	return x < 0|| x >= n || y < 0 || y >=m;
}

 int gr_size[1000005];
 int gr_idx;

 void bfs(int a, int b) {
	 queue<pair<int, int>>q;
	 q.push({ a,b });
	 vis[a][b] = gr_idx;

	 int cnt = 0;
	 while (!q.empty()) {
		 int x = q.front().first;
		 int y = q.front().second;
		 q.pop();
		 cnt++;
		 for (int i = 0; i < 4; i++) {
			 int nx = x + dx[i];
			 int ny = y + dy[i];
			 if (out(nx, ny) || vis[nx][ny] != -1 || arr[nx][ny] == 0)
				 continue;
			 vis[nx][ny] = gr_idx;
			 q.push({ nx,ny });
		 }
	 }

	 
	 gr_size[gr_idx] = cnt;
	 gr_idx++;
 }
 void init() {
	 for (int i = 0; i < n; i++) {
		 for (int j = 0; j < m; j++) {
			 if (arr[i][j]==0||vis[i][j] != -1)
				 continue;
			 bfs(i, j);
		 }
	 }
 }
void input(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			vis[i][j] = -1;
		}
	}
	init();


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j]) 
				continue;
			
			else {
				set<int> gr;
				for (int z = 0; z < 4; z++) {
					int nx = i + dx[z];
					int ny = j + dy[z];
					if (out(nx, ny) || vis[nx][ny] == -1)
						continue;
					gr.insert(vis[nx][ny]);
				}
				int sum = 1;
				for (auto c : gr) {
					sum+=gr_size[c];
				}

				ret = max(ret, sum);
			}
		}
	}
	cout << ret;
}



void run() {


}


int main() {
	fastio
		input();
	run();

}
