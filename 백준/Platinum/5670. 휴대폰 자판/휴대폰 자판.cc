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
using namespace std;
using ll = long long;

const int MAX_NODE = 1000005;

struct Node {
	int next[26];
	int cnt;
	bool isEnd;
};

Node pool[MAX_NODE];
int poolCnt;

int newNode() {
	for (int i = 0; i < 26; i++)
		pool[poolCnt].next[i] = -1;
	pool[poolCnt].cnt = pool[poolCnt].isEnd = 0;
	return poolCnt++;
}

int root;

void insert(const string& s) {
	int cur = root;
	for (char c : s) {
		int idx = c - 'a';
		if (pool[cur].next[idx] == -1) {
			pool[cur].next[idx] = newNode();
			pool[cur].cnt++;
		}
		cur = pool[cur].next[idx];
	}
	pool[cur].isEnd = true;
}

int getKeystroke(const string& s) {
	int cur = pool[root].next[s[0]-'a'];
	int res = 1;

	for (int i = 1; i < s.size(); i++) {


		// 첫 글자이거나 분기점이거나 이전에 단어가 끝났으면 입력
		if (pool[cur].cnt > 1)
			res++;
		else {
			if (pool[cur].isEnd == 1)
				res++;
		}
		cur = pool[cur].next[s[i] - 'a'];
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	while (cin >> n) {
		poolCnt = 0;
		root = newNode();  // 항상 첫 번째 노드 생성

		string words[100005];
		for (int i = 0; i < n; ++i) {
			cin >> words[i];
			insert(words[i]);
		}

		int total = 0;
		for (int i = 0; i < n; ++i) {
			total += getKeystroke(words[i]);
		}

		cout << fixed << setprecision(2) << (double)total / n << "\n";
	}

	return 0;
}
