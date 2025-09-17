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
int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };

int n, t, ret, h, k, m;
string s;
deque<int> b;
deque<int> c;
deque<int> a;
void input() {
	cin >> s;

	int si = s.size();
	for (int i = 0; i < si;i++) {
		if (s[i] == 'A') {
			a.push_back(i);
		}
		else if (s[i] == 'B') {
			b.push_back(i);
		}
		else {
			c.push_back(i);
		}
	}
	//b가 나오면 맨앞에 a를 사용
	//c가 나오면  맨뒤 b를 사용
	while (!a.empty()) {
		int x = a.back();
		a.pop_back();
		if (!b.empty()) {
			int y = b.back();
			if (x < y) {
				b.pop_back();
				ret++;
			}
		}
		else
			continue;
	}
	while (!b.empty()) {
		int x = b.back();
		b.pop_back();
		if (!c.empty()) {
			int y =c.back();
			if (x < y) {
				c.pop_back();
				ret++;
			}
		}
		else
			continue;
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
