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
ll dp[105];

int min_num[8] = { 0,0,1,7,4,2,0,8 };

void input() {
	fill(dp, dp + 105, 1e18);

	dp[1]=9; dp[2] = 1; dp[3] = 7; dp[4] = 4; dp[5] = 2; dp[6] = 6; dp[7] = 8;
	
	for (int i = 8; i <= 100; ++i) {
		for (int j = 2; j <= 7; ++j) {
			//cout << dp[i] << ": " << dp[i - j] << ": " << min_num[j] << "\n";
			dp[i] = min(dp[i], dp[i - j] * 10 + min_num[j]);
		}
	}
	cin >> t;
	while (t--) {
		cin >> n;
		string  r2 = "";
		if (n % 2 == 0) {
			for (int i = 0; i < n / 2; i++)
				r2 += "1";
		}
		else {
			r2 += "7";
			for (int i = 0; i < (n - 3) / 2; i++)
				r2 += "1";
		}

		

		cout << dp[n] << " " << r2 << "\n";
	}
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