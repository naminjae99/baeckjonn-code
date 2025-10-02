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

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

int n, m, ret, k, t, h, w;


int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
	for (int i = 0; i < schedules.size();i++) {
		schedules[i] += 10;
		if (schedules[i] % 100 >= 60) {
			schedules[i] -= 60;
			schedules[i] += 100;
		}
	}
	int answer = 0;

	for (int i = 0; i < schedules.size(); i++) {
		bool flag = 0;
		for (int j = startday; j < startday + 7; j++) {
			if ((j % 7) == 6 || (j % 7) == 0)
				continue;
			if (timelogs[i][j - startday] > schedules[i]) {
				flag = 1;
				break;
			}

		}
		if (flag == 0)
			answer++;
	}



	return answer;
}


