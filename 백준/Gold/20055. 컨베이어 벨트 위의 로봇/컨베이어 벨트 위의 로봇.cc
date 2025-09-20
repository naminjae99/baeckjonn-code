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

deque<pair<int,bool>> arr;

void input() {
	cin >> n >> k;
	for (int i = 0; i < n * 2; i++) {
		int x;
		cin >> x;
		arr.push_back({ x,0});
	}
}

void solve() {
	
	while (1) {
		int cnt = 0;
		for (int i = 0; i < n * 2; i++) {
			if (arr[i].first == 0)
				cnt++;
		}
		if (cnt >= k)
			break;
		ret++;
		arr.push_front(arr.back());
		arr.pop_back();
	
		


		if (arr[n - 1].second)
			arr[n - 1].second = 0;

		for (int i = n - 2; i >= 0; i--) {
			if (arr[i].second&&arr[i+1].first&&arr[i+1].second==0) {
				arr[i].second = 0;

				arr[i + 1].first--;
				arr[i + 1].second = 1;
			}
		}
		if (arr[n - 1].second)
			arr[n - 1].second = 0;

		if (arr[0].first&&arr[0].second==0) {
			arr[0].second = 1;
			arr[0].first--;
		}

		
	}
	cout << ret;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	solve();

	return 0;
}