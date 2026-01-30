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
#include<map>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

deque<int> arr[15];

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";

	vector<int> v;
	for (auto c : timetable) {
		int h = stoi(c.substr(0, 2));
		int m = stoi(c.substr(3, 2));
		v.push_back(h * 60 + m);
	}
	sort(v.begin(), v.end());

	for (auto c : v) {
		bool flag = 0;

		for (int i = 0; i < n; i++) {
			if (540 + i * t >= c) {
				arr[i].push_back(c);
				flag = 1;
				break;
			}
		}
		if (flag == 0)
			arr[n].push_back(c);
	}

	for (int i = 0; i < n; i++) {
		if (arr[i].size() <= m)
			continue;
		else {
		
			for (int j = arr[i].size() - 1;j>=m; j--) {
				arr[i + 1].push_front(arr[i].back());
				arr[i].pop_back();
			}
		}
	}
	int ret = 0;

	for (int i = n - 1; i >= 0; i--) {
		if (arr[i].empty()) {
			ret = 540 + i * t;
			break;
		}
		else if (arr[i].size() == m) {
			ret = arr[i].back() - 1;
			break;
		}
		else if (arr[i].size() < m) {
			ret = 540 + i * t;
            break;
		}

	}

	if (ret / 60 < 10)
		answer += "0";
	answer += to_string(ret / 60)+":";
	if (ret % 60 < 10)
		answer += "0";
	answer += to_string(ret % 60);

	return answer;
}
void input() {
	
}
int main() {
	fastio
		input();

}
