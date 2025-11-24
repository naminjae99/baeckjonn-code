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

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, ret, t, k, Q, L;

struct Node {
	int cnt;
	int arr[2];
}node[6000005];


int idx = 2;
int val[6000005];
int lg = 30;

void push(int x) {
	string s = "";
	for (int i = lg; i >= 0; i--) {
		if (x&(1 << i))
			s += "1";
		else
			s += "0";
	}


	int cur = 1;
	for (auto c : s) {
		if (node[cur].arr[c - '0'] == 0)
			node[cur].arr[c - '0'] = idx++;
		cur = node[cur].arr[c - '0'];
		node[cur].cnt++;
	}
	val[cur] = x;
}
void del(int x) {
	string s = "";
	for (int i = lg; i >= 0; i--) {
		if (x&(1 << i))
			s += "1";
		else
			s += "0";
	}


	int cur = 1;
	for (auto c : s) {
		cur = node[cur].arr[c - '0'];
		node[cur].cnt--;
	}
}
void find(int x) {
	string s = "";
	for (int i = lg; i >= 0; i--) {
		if (x&(1 << i))
			s += "1";
		else
			s += "0";
	}


	int cur = 1;
	for (auto c : s) {


		int ch = c - '0';

		if (node[cur].arr[ch ^ 1] && node[node[cur].arr[ch ^ 1]].cnt)
			cur = node[cur].arr[ch^1];
		else
			cur = node[cur].arr[ch];
	}


	cout << (val[cur] ^ x) << "\n";

}

void input() {
	cin >> n;
	push(0);

	while (n--) {
		int cmd;
		int x;
		cin >> cmd >> x;
		if (cmd == 1) {
			push(x);
		}
		else if (cmd == 2) {
			del(x);
		}
		else {
			find(x);
		}
	}
}
void solve() {



}

int main() {
	fastio;
	input();
	solve();
}











