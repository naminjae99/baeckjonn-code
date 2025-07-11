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
using namespace std;
using ll = long long;


int n, m, k,t;

int trie[100005][11];
bool chk[100005];
int used=1;

vector<int> v;

void insert(string s) {
	int cur = 1;
		
	for (auto c : s) {
		if (trie[cur][c - '0'] == 0) 
			trie[cur][c - '0'] = used++;
		cur = trie[cur][c - '0'];
	}
	chk[cur] = 1;
	v.push_back(cur);
}
bool flag;
void cal(int x) {
	if (flag)
		return;
	for (int i = 0; i < 10; i++) {
		//cur에서 자식이 있고	
		if (trie[x][i] != 0) {
			if (chk[trie[x][i]] == 1) {
				flag = 1;
				return;
			}
			else
				cal(trie[x][i]);
		}
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> t;

	while (t--) {
		memset(chk, 0, sizeof(chk));
		memset(trie, 0, sizeof(trie));
		used = 2;
		v.clear();
		flag = 0;

		cin >> n;
		
		string s;
		while (n--) {
			cin >> s;
			insert(s);
		}
		for (auto c : v) {
			if (flag == 0)
				cal(c);
			else
				break;
		}
		if (flag)
			cout << "NO\n";
		else
			cout << "YES\n";
	}
	
}
