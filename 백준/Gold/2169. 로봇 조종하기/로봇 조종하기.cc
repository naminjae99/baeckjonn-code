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
int dx[4] = { -1,0,0,1 };
int dy[4] = { 0,-1,1,0 };

int n, m, k, ret, h;

int arr[1005][1005];
int dp[1005][1005][2];
int sum[1005][1005];
void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			dp[i][j][0]=dp[i][j][1] = -1e9;
		}
	}

	int sum = 0;
	for (int j = 0; j < m; j++) {
		sum += arr[0][j];
		dp[0][j][0]=dp[0][j][1] = sum;
	}
	for (int i = 1; i < n; i++) {

		dp[i][0][0] = dp[i - 1][0][0] + arr[i][0];

		for (int j = 1; j <m; j++) {
			dp[i][j][0] = max(dp[i - 1][j][0], dp[i][j - 1][0]) + arr[i][j];
		}

		dp[i][m - 1][1] = dp[i - 1][m - 1][1]+arr[i][m-1];
		for (int j = m-2; j >=0; j--) {
			dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j + 1][1]) + arr[i][j];
		}
		for (int j = 0; j < m; j++) {
			if (dp[i][j][0] > dp[i][j][1])
				dp[i][j][1] = dp[i][j][0];
			else
				dp[i][j][0] = dp[i][j][1];
		}
	}
	cout << dp[n - 1][m - 1][0];
}

void solve() {



}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	solve();

	return 0;
}