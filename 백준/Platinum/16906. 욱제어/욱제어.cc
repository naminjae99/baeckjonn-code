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

int n, m, k, t;
int trie[1000005][2];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1, };
bool chk[1000005];

vector<pair<int,int>>  len;
int used = 2;

bool fflag = 0;
string re;
string st[1001];

void dfs(int cur, int idx, int mok, string s) {
	if (fflag)
		return;

	//만들어가다가 접두사가 되는 단어 만나면 종료 
	if (chk[cur] != 0)
		return;
	if (idx == mok) {
		fflag = 1;
		chk[cur] = 1;
		re = s;
		return;
	}
	//접두사중에 단어인거 없음


	if (trie[cur][0] == 0) {
		trie[cur][0] = used++;
		dfs(trie[cur][0], idx + 1, mok, s + '0');
	}
	else {
		if (chk[trie[cur][0]] == 0 && !fflag)
			dfs(trie[cur][0], idx + 1, mok, s + '0');
	}


	if (trie[cur][1] == 0 && !fflag) {
		trie[cur][1] = used++;
		dfs(trie[cur][1], idx + 1, mok, s + '1');
	}
	else {
		if (chk[trie[cur][1]] == 0 && !fflag)
			dfs(trie[cur][1], idx + 1, mok, s + '1');
	}


}
bool insert(int i,int l) {
	fflag = 0;
	int cur = 1;


	if (trie[cur][0] == 0) {
		trie[cur][0] = used++;
		dfs(trie[cur][0], 1, l, "0");
	}
	else {
		if (!fflag)
			dfs(trie[cur][0], 1, l, "0");
	}


	if (trie[cur][1] == 0 && !fflag) {
		trie[cur][1] = used++;
		dfs(trie[cur][1], 1, l, "1");
	}
	else {
		if (!fflag)
			dfs(trie[cur][1], 1, l, "1");
	}

	if (fflag) {
		st[i] = re;
		//cout << re << "\n";
		return 1;
	}
	return 0;
}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n;
	bool flag = 0;
	int x;
	for (int i = 0; i < n; i++) {
		cin >> x;
		len.push_back({ x,i });
	}
	sort(len.begin(), len.end());
	for (auto c : len) {
		if (insert(c.second, c.first) == 0)
			flag = 1;
	}

	if (flag)
		cout << -1;
	else {
		cout << 1 << "\n";
		for (int i = 0; i < n; i++) {
			cout << st[i] << "\n";
		}
	}
}
