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

int dx[4] = {-1,0,1,0 };
int dy[4] = { 0,1,0,-1 };


int n, m, t, k, ret;

int st, en;
int dp[305][305][305];

void input() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> dp[0][i][j];
			if (dp[0][i][j] == 0)
				dp[0][i][j] = 1e9;
            if(i==j)
                dp[0][i][i]=0;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[k][i][j] = min(dp[k - 1][i][j], dp[k-1][i][k]+dp[k-1][k][j]);
			}
		}
	}

	while (m--) {
		cin >> k >> st >> en;
		int ans = dp[k-1][st][en];
		if (ans == 1e9)
			cout << -1;
		else
			cout << ans;
		cout << "\n";
	}
}

void solve() {

}

void calculator() {


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	input();
	solve();


	return 0;
}