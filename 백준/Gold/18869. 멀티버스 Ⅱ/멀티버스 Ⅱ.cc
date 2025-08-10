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
#include<cfloat>
#include<array>
using namespace std;
using ll = long long;


int n, m, k, t;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

vector<pair<int, int>> v[105];
int arr[105][10005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n>>m;

	for (int i = 0; i < n; i++) {
		int x;
		for (int j = 0; j < m; j++) {
			cin >> x;
			v[i].push_back({ x,j });
		}
		sort(v[i].begin(), v[i].end());
		for (int j = 0; j < m; j++) {
			pair<int, int> chk = { v[i][j].first,0 };
			int it = lower_bound(v[i].begin(), v[i].end(), chk) - v[i].begin();
			arr[i][v[i][j].second] = it;
		}
		
	
		
	}
	int cnt = 0;
	for (int i = 0; i < n-1; i++) {

		for (int j = i + 1; j < n; j++) {

			bool flag = 0;
			for (int ii = 0; ii < m; ii++) {
				if (arr[i][ii] != arr[j][ii]) {
					flag = 1;
					break;
				}
			}
			if (flag == 0)
				cnt++;

		}

	}
	cout << cnt;
}
