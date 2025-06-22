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


set<pair<int, int>> xy[100001];
int arr[2001][2001];
int par[100001];
int n, m, k;

int find(int x) {
	if (par[x] ==x)
		return x;
	return par[x]=find(par[x]);
}
void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	par[b] = a;
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

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL);

	cin >> n >>k;
	int a, b,x,y;
	for (int i = 1; i <= k; i++) {
		cin >> a >> b;
		arr[a][b] = i;
		xy[i].insert({ a,b });
		par[i] = i;
	}

	
	

	//pr();

	vector<pair<int, int>> tmp;
	vector<pair<int, int>> tmp2;
	int cnt;

	while (1) {
		for (int i = 1; i <= k; i++) {
			for (auto c : xy[i]) {
				for (int j = 0; j < 4; j++) {
					x = c.first + dx[j];
					y = c.second + dy[j];
					if (x<1 || x>n || y<1 || y>n)
						continue;
					if (arr[x][y] == 0)
						continue;
					if (arr[x][y] != par[i]) {
						uni(i, arr[x][y]);
					}
				}
			}
		}

		//부모그룹의 갯수
		cnt = 0;
		for (int i = 1; i <= k; i++) {
			if (par[i]==i) {
				cnt++;
			}
		}
		if (cnt ==1) {
			cout << ti;
			return 0;
		}
		ti++;


		for (int i = 1; i <= k; i++) {
			
			for (auto c : xy[i]) {
				//cout << i << "그룹의 " << c.first << ", " << c.second << "ㅎㅇ\n";
				for (int j = 0; j < 4; j++) {
					 x = c.first + dx[j];
					 y = c.second + dy[j];
					if (x<1 || x>n || y<1 || y>n)
						continue;
					if (arr[x][y] == 0) {
						arr[x][y] = i;
						tmp2.push_back({ x,y });
					}
					else if (par[arr[x][y]] == par[i])
						continue;
					else {
						tmp.push_back({ i,arr[x][y] });
					}
				}
			}
			for (auto c : tmp2)
				xy[i].insert(c);
			tmp2.clear();
			for (auto c : tmp)
				uni(i,c.second);
			tmp.clear();
			//pr();
		}
		

		
	}
}