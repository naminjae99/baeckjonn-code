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
using namespace std;
using ll = long long;
int dx[4] = {-1,0,0,1};
int dy[4] = {0,-1,1,0 };

int n, m, t, ret, h, k;
vector<ll> v;
void input() {
	
	cin >> n ;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		reverse(s.begin(), s.end());
		v.push_back(stol(s));
	}
	sort(v.begin(), v.end());
	for (auto c : v) {
		cout << c << "\n";
	}

}

void solve() {

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);



	/*
	cin >> t;
	for (int i = 1; i <= t; i++) {
		input();

	}*/
	input();
	solve();
}
