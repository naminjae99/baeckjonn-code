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
#include<deque>
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
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;

int dx[4] = { -1,1,0,0};
int dy[4] = {0,0,-1,1 };
int n, m, ret, k, t, Q;


int arr[105][105];
int solution(int n, vector<vector<int>> results) {
	for (int i = 0; i < results.size(); i++) {
		int x = results[i][0];
		int y = results[i][1];
		arr[x][y] = 1;
		arr[y][x] = -1;
	}

	for (int z = 1; z <= n; z++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] != 0)
					continue;
				if (arr[i][z] == 1 && arr[z][j] == 1)
					arr[i][j] = 1;
				if (arr[i][z] == -1 && arr[z][j] == -1)
					arr[i][j] = -1;
			}
		}
	}
	int answer = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i == j)
				continue;
			if (arr[i][j] == 0) {
				cnt = 1;
				break;
			}
		}
		if (cnt == 0)
			answer++;
	}
	
	return answer;
}