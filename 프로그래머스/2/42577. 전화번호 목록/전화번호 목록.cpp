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
#include<iomanip>
#include<deque>
#include<array>
#include<limits.h>
#include<cfloat>
using namespace std;

int trie[20000005][10];
int used, n, idx;
int chk[20000005];
bool en[20000005];
bool answer = 1;
void insert(string s) {
	int cur = 1;
	for (auto c : s) {
		int x = c - '0';
		if (trie[cur][x] == 0)
			trie[cur][x] = used++;
		cur = trie[cur][x];
		chk[cur]++;
	}
	en[cur] = 1;
}
void check(string s) {
	int cur = 1;
	for (auto c : s) {
		int x = c - '0';
		if (trie[cur][x] == 0)
			return;
		cur = trie[cur][x];
	}

	if (chk[cur]>1) {
		answer = 0;
	}
}
bool solution(vector<string> phone_book) {
	used = 2;
	for (auto c : phone_book) 
		insert(c);
	for (auto c : phone_book) {
		check(c);
		if (answer == 0)
			break;
	}

	return answer;
}


