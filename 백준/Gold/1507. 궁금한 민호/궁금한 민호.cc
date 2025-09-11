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
using namespace std;
using ll = long long;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0 };

int n, m, t, ret, h, k;

int arr[25][25];
int cpy[25][25];

void input() {
	
	cin >> n ;
	int x;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		
		}
	}


	for (int z = 0; z < n; z++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if ( i == z || j == z)continue;
				if (arr[i][j] == arr[i][z] + arr[z][j]) {
					cpy[i][j] = 1;
				}
				if (arr[i][j] > arr[i][z] + arr[z][j]) {
					ret = -1;
					return;
				}
			}
		}
	}

	
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (cpy[i][j]==0)
				ret += arr[i][j];
		}
	}
}

void solve() {

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);



	/*
	cin >> t;
	for (int i = 1; i <= t; i++) {
		input();

	}*/
	input();
	solve();
	cout << ret;
}
