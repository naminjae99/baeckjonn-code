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
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int n, t, ret, m;
string s;
int arr[100005];
ll re[100005];

ll res;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		re[i] = -1;
	}
	stack<int> s;
	for (int i = n - 1; i >= 0; i--) {
		while (!s.empty() && arr[s.top()] < arr[i]) {
			s.pop();
		}

		if (!s.empty()) {
			re[i] = s.top()-i-1;
		}
		s.push(i);
	}
	for (int i = 0; i < n; i++) {
		if (re[i] == -1) {
			res += (n - 1) - i;
		}
		else
			res += re[i];
	}
}

void solve() {
	

}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	input();
	solve();

	cout << res;
}
