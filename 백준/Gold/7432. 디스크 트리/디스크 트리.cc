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
using namespace std;
using ll = long long;


int n, m, k,t;

map<string, int> trie[20001];
int used = 2;

void insert(string s) {
	stringstream ss(s);
	string word;

	int cur = 1;
	while (getline(ss, word, '\\')) {
		if (trie[cur].find(word) == trie[cur].end()) {
			trie[cur][word] = used++;
		}
		cur = trie[cur][word];
	}
}
void p(int x) {
	for (int i = 0; i < x; i++)
		cout << ' ';

}
void dfs(int now, int dep) {
	for (auto c : trie[now]) {
		p(dep);
		cout << c.first << "\n";
		dfs(c.second, dep + 1);
	}

}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n;
	while (n--) {
		string s;
		cin >> s;

		insert(s);
	}
	dfs(1, 0);
}
