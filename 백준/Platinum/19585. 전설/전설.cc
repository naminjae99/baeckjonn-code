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
bool chk1[8000008];
unordered_map<string, bool> mp;

void insert(string s, bool mode) {
	int cur = 1;
	for (auto c : s) {
		if (trie[cur][c - 'a'] == 0)
			trie[cur][c - 'a'] = used++;
		cur = trie[cur][c - 'a'];
	}
	if (mode)
		chk1[cur] = 1;
	else
		chk0[cur] = 1;
}
bool check1(string s) {
	int cur = 1;
	for (auto c : s) {
		if (trie[cur][c - 'a'] == 0)
			return 0;
		cur = trie[cur][c - 'a'];
	}
	if (chk1[cur] == 1)
		return 1;
	return 0;
}
bool check(string s) {
	int cur = 1;
	for (int i = 0; i < (int)s.size() - 1; i++) { // 색상은 적어도 한 글자, 팀이름도 한 글자
		int c = s[i] - 'a';
		if (trie[cur][c] == 0) break;
		cur = trie[cur][c];
		if (chk0[cur]) {
			string team = s.substr(i + 1);
			if (mp.find(team) != mp.end()) return true;
		}
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
		mp[s] = 1;
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
