#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <tuple>
#include<unordered_map>
using namespace std;
using ll = long long;
int n, k, m;

int dx[4] = { -1, 1, 0, 0 }; // 상, 하, 좌, 우
int dy[4] = { 0, 0, -1, 1 };
int arr[100005];
int tree[400005];

int build(int no, int s, int e) {
	if (s == e) {
		if (arr[s] > 0)
			return tree[no] = 1;
		else if (arr[s] == 0)
			return tree[no] = 0;
		else
			return tree[no] = -1;
	}
	int mid = (s + e) >> 1;
	int a = build(no << 1, s, mid);
	int b = build(no*2+ 1, mid + 1, e);
	return tree[no] = a * b;
}
int upd(int no, int s, int e, int idx, int x) {
	if (e < idx || idx < s)
		return tree[no];
	if (s == e) {
		if (x > 0)
			tree[no] = 1;
		else if (x == 0)
			tree[no] = 0;
		else
			tree[no] = -1;
		return tree[no];
	}
	int mid = (s + e) >> 1;
	int a = upd(no * 2, s, mid,idx, x);
	int b = upd(no * 2 + 1, mid + 1, e,idx, x);
	return tree[no] = a * b;
}
int query(int no, int s, int e, int l, int r) {
	if (e < l || r < s)
		return 1;
	if (l <= s && e <= r)
		return tree[no];
	int mid = (s + e) >> 1;
	int a = query(no * 2, s, mid, l, r);
	int b = query(no * 2 + 1, mid + 1, e, l, r);
	return a * b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	while (cin >> n) {
		cin >> m;
		for (int i = 1; i <= n; i++) 
			cin >> arr[i];
		build(1, 1, n);

		vector<char>re;
		char cmd;
		int a, b;
		while (m--) {
			cin >> cmd;
			if (cmd == 'C') {
				cin >> a >> b;
				upd(1, 1, n, a, b);
			}
			else {
				cin >> a >> b;
				int tmp=query(1, 1, n, a, b);
				if (tmp > 0)
					re.push_back('+');
				else if (tmp == 0)
					re.push_back('0');
				else
					re.push_back('-');
			}
		}
		for (auto c : re)
			cout << c;
		cout << "\n";
	}
}
