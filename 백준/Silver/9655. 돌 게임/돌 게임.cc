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
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };

int n, m, k, ret, h;
bool arr[1005];

void input() {
	cin >> n;

	arr[1] = arr[3] = 1;
	arr[2] = 0;

	//3이나 1을 뺸게 값을 3으로 나눈 나머지가 2가되도록

	for (int i = 4; i <= n; i++) {
		arr[i] = !arr[i - 1];
	}
	if (arr[n])
		cout << "SK";
	else
		cout << "CY";
}



void solve() {

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
	solve();
	return 0;
}