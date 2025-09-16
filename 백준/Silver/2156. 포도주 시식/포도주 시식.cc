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
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int n, t, ret, m;

int arr[10005];
int dp[10005][3];
void input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	memset(dp, -1, sizeof(dp));

	dp[0][1] = arr[0];
	dp[0][0] = 0;

	for (int i = 1; i < n; i++) {
		if(dp[i-1][1]!=-1)
		dp[i][2] = dp[i - 1][1] + arr[i];
		if(dp[i-1][0]!=-1)
		dp[i][1] = dp[i - 1][0] + arr[i];

		
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		
		dp[i][0] = max(dp[i][0], dp[i - 1][2]);
	}
	
	
	for (int i = 0; i < 3; i++)
		ret = max(ret, dp[n - 1][i]);
	cout << ret;
}
void solve() {


}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	input();
	solve();


}
