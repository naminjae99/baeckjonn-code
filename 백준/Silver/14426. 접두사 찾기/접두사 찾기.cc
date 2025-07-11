#include<iostream>
#include <unordered_map>
#include<queue>
#include <unordered_set>
#include<string>
#include<memory.h>
using namespace std;

int n, m;
int root = 1;
int trie[50005][26];
int chk[50005];
int num = 2;
int re;
void insert(string s) {
	int cur = root;
	for (auto i : s) {
		if (trie[cur][i-'a'] == 0) {
			trie[cur][i-'a'] = num++;
		}
		cur = trie[cur][i-'a'];
	}
	chk[cur] = 1;
}
int find(string s) {
	int cur = root;
	for (auto i : s) {
		if (trie[cur][i - 'a'] == 0)
			return 0;
		cur = trie[cur][i - 'a'];
	}
	return 1;
}

int main() {

	cin >> n >> m;
	for (int i = 0; i < 50005; i++) {
		fill(trie[i], trie[i] + 26, 0);
	}
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		insert(s);
	}
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		if(find(s))
			re++;
	}
	cout << re;
}