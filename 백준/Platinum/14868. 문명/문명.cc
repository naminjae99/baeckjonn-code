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
using namespace std;
using ll = long long;

queue<pair<int, int>> city;
queue<pair<int, int>> q;

int arr[2001][2001];
int par[100001];
int n, m, k;

int find(int x) {
	if (par[x] ==x)
		return x;
	return par[x]=find(par[x]);
}
int uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return 0;
	par[b] = a;
	return 1;
}

void pr() {
	
	for (int j = n; j >= 1; j--) {
		for (int i = 1; i <= n; i++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int ti = 0;
int cnt;
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL);
	cout.tie(0);
	cin >> n >>k;
	int a, b,x,y,nx,ny;
	for (int i = 1; i <= k; i++) {
		cin >> a >> b;
		arr[a][b] = i;
		city.push({ a,b });
		par[i] = i;
	}

	cnt = k;
	

	//pr();

	
	while (1) {

		// merge
		while (!city.empty()) {
			x = city.front().first;
			y = city.front().second;
			city.pop();
			q.push({ x,y });
			for (int i = 0; i < 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx<1 || nx>n || ny<1 || ny>n)
					continue;
				if (arr[nx][ny] == 0)
					continue;
				if (par[arr[nx][ny]] != par[arr[x][y]]) {
					if(uni(arr[nx][ny], arr[x][y]))
						cnt--;
				}
			}
		}
	//	pr();

		//cout << "남은 부모: " << cnt << "\n";
		if (cnt ==1) {
			cout << ti;
			return 0;
		}
		ti++;

		while (!q.empty()) {
			x = q.front().first;
			y = q.front().second;
			q.pop();
			for (int i = 0; i < 4; i++) {
				nx = x + dx[i];
				ny = y + dy[i];
				if (nx<1 || nx>n || ny<1 || ny>n)
					continue;
				if (arr[nx][ny] == 0) {
					city.push({ nx,ny });
					arr[nx][ny] = arr[x][y];
					continue;
				}
				if (par[arr[nx][ny]] != par[arr[x][y]]) {
					city.push({ nx,ny });
					if(uni(arr[nx][ny],arr[x][y]))
						cnt--;
				}
			}
		
		}
	//	pr();

		
	}
}