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

int arr[150][150];
int tmp[150][150];
int vis[150][150];
void p() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout <<setw(2)<< arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}
void turn(int s) {
	if (s == 0)
		return;
	memcpy(tmp, arr, sizeof(tmp));
	int block = pow(2, s);
	int hf = block / 2;

	for (int i = 0; i < n; i += block) {
		for (int j = 0; j < n; j += block) {

			for (int a = 0; a < block; a++) {
				for (int b = 0; b < block; b++) {
					tmp[i+b][j+(block-1)-a] = arr[i+a][j+b];
				}
			}

		}
	}
	memcpy(arr, tmp, sizeof(tmp));
}
void del() {
	memcpy(tmp, arr, sizeof(tmp));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0)
				continue;
			int cnt = 0;
			for (int z = 0; z < 4; z++) {
				int nx = i + dx[z];
				int ny = j + dy[z];
				if (nx < 0 || nx >= n || ny < 0 || ny >= n)
					continue;
				if (arr[nx][ny] == 0)
					continue;
				cnt++;
			}
			if (cnt < 3)
				tmp[i][j]--;
		}
	} 
	memcpy(arr, tmp, sizeof(tmp));
}

void input() {
	cin >> k >> m;
	n = pow(2, k);	
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) 
			cin >> arr[i][j];
		
	
	while (m--) {
		int x;
		cin >> x;
		turn(x);
		del();
	}

	int mx = 0;
	int total = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0)
				continue;
			total += arr[i][j];
			if (vis[i][j])
				continue;


			int cnt = 1;
			queue<pair<int, int>> q;
			q.push({ i,j });
			vis[i][j] = 1;

			while (!q.empty()) {
				int x = q.front().first;
				int y = q.front().second;
				q.pop();
				for (int z = 0; z < 4; z++) {
					int nx = x + dx[z];
					int ny = y + dy[z];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;
					if (vis[nx][ny])
						continue;
					if (arr[nx][ny] == 0)
						continue;
					cnt++;
					q.push({ nx,ny });
					vis[nx][ny] = 1;
				}
			}

			mx = max(mx, cnt);

		}
	}

	cout << total << "\n";
	cout << mx << "\n";

}
void solve() {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	solve();
	//cout << ret;
	return 0;
}