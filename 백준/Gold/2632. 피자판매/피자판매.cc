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

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


int n, m, t,k;
int ret;



int a[1005];
int b[1005];
int as[1005];
int bs[1005];

int  acnt[1000005];

int  bcnt[1000005];

void input() {
	cin >> k >> m >> n;
	int x;
	int sum = 0;
	for (int i = 1; i <= m; i++) {
		cin >> x;
		sum += x;
		a[i] = x;
		as[i] = sum;
	}
	sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		sum += x;
		b[i] = x;
		bs[i] = sum;
	}

}
void solve() {
	for (int i = 1; i <=m; i++) {
		for (int j = 1; j <=m; j++) {
			if (i <= j) {
				acnt[as[j] - as[i - 1]]++;
			}
			else {
				if (j + 1 == i)
					continue;
				acnt[as[m] - as[i - 1] + as[j]]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i <= j) {
				bcnt[bs[j] -bs[i - 1]]++;
			}
			else {
				if (j + 1 == i)
					continue;
				bcnt[bs[n] - bs[i - 1] + bs[j]]++;
			}
		}
	}

	for (int i = 1; i < k; i++) {
		ret += acnt[i] * bcnt[k - i];
	}
	ret += bcnt[k];
	ret += acnt[k];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	input();
	solve();
	cout << ret;
	return 0;
}