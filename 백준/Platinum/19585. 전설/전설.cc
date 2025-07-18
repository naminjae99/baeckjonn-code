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
#include<map>
#include<iomanip>
#include<array>
using namespace std;
using ll = long long;


int n, m, k, t;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int trie[8000008][26];
int used = 2;
bool chk0[8000008];
unordered_set<string> mp;

void insert(string s, bool mode) {
	int cur = 1;
	for (auto c : s) {
		if (trie[cur][c - 'a'] == 0)
			trie[cur][c - 'a'] = used++;
		cur = trie[cur][c - 'a'];
	}
	chk0[cur] = 1;
}

bool check(string s) {
	int cur = 1;
	int si = s.size();
	for (int i = 0; i < si - 1; i++) {  // 색상은 앞에서 시작하므로 i < si - 1
		int c = s[i] - 'a';
		if (trie[cur][c] == 0)
			return false;
		cur = trie[cur][c];

		if (chk0[cur] && mp.count(s.substr(i + 1)))
			return true;
	}
	return false;
}


int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n >> m;
	string s;
	while (n--) {
		cin >> s;
		insert(s, 0);
	}
	while (m--) {
		cin >> s;
		mp.insert(s);
		//insert(s, 1);
	}
	cin >> n;
	while (n--) {
		cin >> s;
		if (check(s)) {
			cout << "Yes\n";
		}
		else
			cout << "No\n";
	}

}
