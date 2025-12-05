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
#include<deque>
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
#include<map>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;

int dx[8] = {-1,0,1,-1,1,-1,0,1  };
int dy[8] = { 1,1,1,0,0,-1,-1,-1 };
int n, m, ret, k, Q, L;
int arr[100005];
string str[100005];
int val[3200005];
int trie[3200005][2];
int idx = 2;

void insert(string s,int x) {
	int cur = 1;
	for (auto c : s) {
		if (trie[cur][c - '0'] == 0)
			trie[cur][c - '0'] = idx++;
		cur = trie[cur][c - '0'];
	}
	val[cur] = x;
}
void input() {
	cin >> n;
	int x;

	int mx = 0;
	for (int i = 0; i < n; i++) {
		cin >> x;
		arr[i] = x;
		mx = max(mx, x);
	}
	int lg =0;
	while ((1 << lg) <= mx)
		lg++;


	for (int i = 0; i < n; i++) {
		string s = "";
		x = arr[i];
		for (int j = lg; j >= 0; j--) {
			if (x&(1 << j))
				s += "1";
			else
				s += "0";
		}

		str[i] = s;
		insert(s, x);
	}

	for (int i = 0; i < n; i++) {
		
		int cur = 1;

		for (int j = 0; j <= lg; j++) {
			if (str[i][j] == '0') {
				if (trie[cur][1] != 0)
					cur = trie[cur][1];
				else
					cur = trie[cur][0];
			}
			else {
				if (trie[cur][0] != 0)
					cur = trie[cur][0];
				else
					cur = trie[cur][1];
			}
		}
		ret = max(ret, val[cur] ^ arr[i]);

	}
	cout << ret;
}
void solve() {



}

int main() {
	fastio;
	input();
	solve();
}




