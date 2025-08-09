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
#include<map>
#include<iomanip>
#include<cfloat>
#include<array>
using namespace std;
using ll = long long;


int n, m, k, t;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


int ta[1000005][26];
int ua = 2;
int ca[1000005];

int tb[1000005][26];
int ub = 2;
int cb[1000005];
void insert(string s, bool mode) {
	if (mode == 0) {
		int cur = 1;
		for (auto c : s) {
			int ch = c - 'a';
			if (ta[cur][ch] == 0)
				ta[cur][ch] = ua++;
			cur = ta[cur][ch];
			ca[cur]++;
		}
	}
	else {
		
		int cur = 1;
		for (int i = s.size() - 1; i >= 0;i--) {
			int ch = s[i] - 'a';
			if (tb[cur][ch] == 0)
				tb[cur][ch] = ub++;
			cur = tb[cur][ch];
			cb[cur]++;
		}
	}
}
void erase(string s, bool mode) {
	if (mode == 0) {
		int cur = 1;
		for (auto c : s) {
			cur = ta[cur][c - 'a'];
			ca[cur]--;
		}
		//ca[cur]--;
	}
	else {
		int cur = 1;
		for (int i = s.size() - 1; i >= 0; i--) {
			cur = tb[cur][s[i]-'a'];
			cb[cur]--;
		}
	}
}
int f(string s, bool mode) {
	if (mode == 0) {
		int cur = 1;
		for (auto c : s) {
			int ch = c - 'a';
			if (ta[cur][ch] == 0)
				return 0;
			cur = ta[cur][ch];
		}
		return ca[cur];
	}
	else {
		int cur = 1;
		for (int i = s.size() - 1; i >= 0; i--) {
			int ch = s[i] - 'a';
			if (tb[cur][ch] == 0)
				return 0;
			cur = tb[cur][ch];
		}
		return cb[cur];
	}
}

unordered_map<string, int>aa;
unordered_map<string, int>bb;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	string cmd;
	char a;
	string s;
	while (n--) {
		cin >> cmd;
		if (cmd[0] == 'a') {
			cin >> a >> s;
			if (a == 'A') {
				for (int i = 1; i <= s.size(); i++) {
					aa[s.substr(0, i)]++;
				}
			}
			else {
				reverse(s.begin(), s.end());
				for (int i = 1; i <= s.size(); i++) {
					bb[s.substr(0, i)]++;
				}
			}
		}
		else if (cmd[0] == 'd') {
			cin >> a >> s;
			if (a == 'A') {
				for (int i = 1; i <= s.size(); i++) {
					aa[s.substr(0, i)]--;
				}
			}
			else {
				reverse(s.begin(), s.end());

				for (int i = 1; i <= s.size(); i++) {
					bb[s.substr(0, i)]--;
				}
			}
		}
		else {
			cin >> s;
			int si = s.size();
			int cnt = 0;
			string rs = s;
			reverse(rs.begin(), rs.end());
			for (int i = 1; i < si ; i++) {
			//	cout << s.substr(0, i) << " , " << s.substr(i, si - i) << "\n";
			//	cout << f(s.substr(0, i), 0)<<" , " << f(s.substr(i, si - i), 1)<<"\n";
				int a = aa[s.substr(0, i)];
				if (a != 0) {
					cnt += a * bb[rs.substr(0, si - i)];
				}
				
			}
			cout << cnt << "\n";
		}
	}
}
