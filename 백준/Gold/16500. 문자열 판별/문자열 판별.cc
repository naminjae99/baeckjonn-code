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

string s;
int n;
bool dp[105];

int trie[10005][26];
int idx = 2;
bool chk[10005];

void insert(string st) {
	int cur = 1;
	for (char c : st) {
		int ch = c - 'a';
		if (!trie[cur][ch])
			trie[cur][ch] = idx++;
		cur = trie[cur][ch];
	}
	chk[cur] = true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> s;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		insert(tmp);
	}

	int len = s.size();
	dp[0] = true;

	for (int i = 0; i < len; i++) {
		if (!dp[i]) continue;

		int cur = 1;
		for (int j = i; j < len; j++) {
			int ch = s[j] - 'a';
			if (!trie[cur][ch]) break;
			cur = trie[cur][ch];
			if (chk[cur])
				dp[j + 1] = true;
		}
	}

	cout << dp[len];
}
