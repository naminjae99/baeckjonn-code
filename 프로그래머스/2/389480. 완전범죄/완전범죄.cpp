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

int cnt[4][4];
int dp[150];
int ed[150][4][4];

bool dfs(int x, int mm) {
	dp[x] = 1e9; // 아주 큰 값으로 초기화 (min 비교용)

	//같은 a증가로 b를 최대로 줄이면 된다

	for (int i = 3; i >= 1; i--) {
		if (ed[x-1][1][i]<cnt[1][i]) {
			if (dp[x] > dp[x - 1] - i) {
				dp[x] = dp[x - 1] - i;
				for (int a = 1; a <= 3; a++)
					for (int b = 1; b <= 3; b++)
						ed[x][a][b] = ed[x - 1][a][b];
				ed[x][1][i]++;
			}
			break;
		}
	}

	// 2칸 전에서 오는 경우
	if (x > 1) {
		for (int i = 3; i >= 1; i--) {
			if (ed[x - 2][2][i] < cnt[2][i]) {
				if (dp[x] > dp[x - 2] - i) {
					dp[x] = dp[x - 2] - i;
					for (int a = 1; a <= 3; a++)
						for (int b = 1; b <= 3; b++)
							ed[x][a][b] = ed[x - 2][a][b];
					ed[x][2][i]++;
				}
				break;
			}
		}
	}

	// 3칸 전에서 오는 경우
	if (x > 2) {
		for (int i = 3; i >= 1; i--) {
			if (ed[x - 3][3][i] < cnt[3][i]) {
				if (dp[x] > dp[x -3] - i) {
					dp[x] = dp[x - 3] - i;
					for (int a = 1; a <= 3; a++)
						for (int b = 1; b <= 3; b++)
							ed[x][a][b] = ed[x -3][a][b];
					ed[x][3][i]++;
				}
				break;
			}
		}
	}

	return dp[x] < mm;
}

int solution(vector<vector<int>> info, int n, int m) {


	for (auto c : info) {
		cnt[c[0]][c[1]]++;
		dp[0] += c[1];
	}

	if (dp[0] < m) return 0;

	for (int i = 1; i < n; i++) {
		if (dfs(i, m)) return i;
	}
	return -1;
}