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
#include<cfloat>
using namespace std;
using ll = long long;
int dx[5] = { 0,0,0,-1,1 };
int dy[5] = { 0,1,-1,0,0 };

int n, t, ret, h, k,m;
int arr[2005];


void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		int st = 0;
		int en = n - 1;

		while (st < en) {
			if (en == i)
				en--;
			if (st == i)
				st++;
			if (st == en)
				break;
			//cout << arr[i] << "만들기: " << st << ", " << en << "\n";
			int tmp = arr[st] + arr[en];
			if (tmp == arr[i]) {
				ret++;
				break;
			}
			else if (tmp < arr[i]) {
				st++;
			}
			else {
				en--;
			}

		}
	}

	
}


void solve() {

	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	input();
	solve();
	cout << ret;
	
}
