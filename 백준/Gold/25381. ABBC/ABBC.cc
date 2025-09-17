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
queue<int> b;
queue<int> c;

void input() {
	cin >> s;
	int si = s.size();
	for (int i = si - 1; i >= 0; i--) {
		if (s[i] == 'A') {
			if (b.empty())
				continue;
			else {
				ret++;
				b.pop();
			}
		}
		else if (s[i] == 'B') {
			if (c.empty()) {
				b.push(1);
			}
			else {
				ret++;
				c.pop();
			}
		}
		else {
			c.push(1);
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
