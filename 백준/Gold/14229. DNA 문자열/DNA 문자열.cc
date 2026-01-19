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


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, ret, k;
char arr[4] = { 'A','C','G','T' };

int trie[1000005][4];
int idx = 2;
bool chk[1000005];

int conv(char c) {
	if (c == 'A')
		return 0;
	else if (c == 'C')
		return 1;
	else if (c == 'G')
		return 2;
	return 3;
}

int push(string s) {
	int cur = 1;
	for (auto c : s) {
		int ch = conv(c);
		if (trie[cur][ch] == 0)
			trie[cur][ch] = idx++;
		cur = trie[cur][ch];
	}
	if (chk[cur])
		return 0;
	chk[cur] = 1;
	return 1;
}
struct f {
	int cur;
	string s;
};

string find(int len) {

	queue<f> q;
	q.push({ 1,"" });

	while (!q.empty()) {
		int sz = q.size();


		while (sz--) {
			int cur = q.front().cur;
			string s = q.front().s;
			q.pop();

			for (int i = 0; i < 4; i++) {
				if (trie[cur][i] == 0) {
					string re = s;
					re += arr[i];
					for (int j = re.size(); j < len; j++)
						re += 'A';
					return re;
				}
				else {
					q.push({ trie[cur][i],s + arr[i] });
				}
			}
		}

	}
	return "";
		
}
void input() {
	string s;
	cin >> s;

	int sz = s.size();

	//i는 길이
	for (int i = 1; i <= sz; i++) {
		int cnt = 0;
		//st는 시작지점
		for (int st = 0; st <= (sz - i); st++) {
			string tmp = s.substr(st,i);
			cnt += push(tmp);
		}
		//모든경우의 수 다 있는경우
		if (cnt == pow(4, i))
			continue;

		//길이가 i인거중에 없는거 찾기
		cout<<find(i);
		return;
	}
}
int main() {
	fastio
	input();
}
