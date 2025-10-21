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

int dx[4] = { 0,0,1,-1};
int dy[4] = {1,-1,0,0 };
int n, m, ret, k, t, Q;


long long solution(int n, vector<int> times) {
	ll left = 0;
	ll right = 1e18;

	ll mid;
	long long answer = 0;
	while (left <= right) {
		mid = (right + left) / 2;
		
		ll cnt = 0;
		for (auto c : times) {
			cnt += mid /c;
		}

		//성공시 시간 내리기
		if (cnt >= n) {
			answer = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	
	return answer;
}
