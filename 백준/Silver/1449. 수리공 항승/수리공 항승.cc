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
#include<cfloat>
using namespace std;
using ll = long long;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, t, ret, h, k,m;
int arr[1005];
void input() {
	cin >> n >> m;

	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr[x] = 1;
	}

	for (int i = 1; i <= 1000; i++) {
		if (arr[i]) {
			ret++;
			i += m - 1;
		}
	}
}

void solve() {
	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	input();
	solve();
	
	cout << ret;
}
