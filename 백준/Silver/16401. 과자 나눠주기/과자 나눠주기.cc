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

int dx[8] = { 0,-1,-1,-1,0,1,1,1 };
int dy[8] = { 1,1,0,-1,-1,-1,0,1 };
int n, m;
int arr[1000005];

void input() {
	cin >> n >> m;
	int en = 0;
	for (int i = 0; i < m; i++) {
		cin >> arr[i];
		en = max(arr[i], en);
	}
	int st = 1;
	

	while (st <= en) {
		int mid = (st + en) / 2;
	
		int cnt = 0;
		for (int i = 0; i < m; i++) {
			cnt += (arr[i] / mid);
			if (cnt >= n) {
	
				st = mid + 1;
				break;
			}
		}

		if (cnt < n) {
			en = mid - 1;
		}
	}

	cout << st-1;
}
void solve() {

}

int main() {
	input();
	solve();
	return 0;
}
