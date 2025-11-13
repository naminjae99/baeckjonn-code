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
int arr[100005];

int tree[400005];
int lazy[400005];

int build(int no, int s, int e) {
	if (s == e) {
		return tree[no] = arr[s];
	}
	int mid = (s + e) / 2;
	build(no * 2, s, mid);
	build(no * 2 + 1, mid + 1, e);
	return tree[no] = tree[no * 2] ^ tree[no * 2 + 1];
}
void down(int no, int s, int e) {
	if (lazy[no]) {
		if (s != e) {
			lazy[no * 2] += lazy[no];
			lazy[no * 2 + 1] += lazy[no];
		}
		if (lazy[no] % 2 == 1) {
			
			tree[no] = (e-s+1)-tree[no];
		}
		lazy[no] = 0;
	}
}

int query(int no, int s, int e, int l, int r) {
	down(no, s, e);
	if (e < l || r < s)
		return 0;
	if (l <= s && e <= r)
		return tree[no];

	int mid = (s + e) / 2;
	int a = query(no * 2, s, mid, l, r);
	int b = query(no * 2 + 1, mid + 1, e, l, r);
	return a + b;
}
int upd(int no, int s, int e, int l, int r) {
	down(no, s, e);
	if (e < l || r < s)
		return tree[no];
	if (l <= s && e <= r) {
		lazy[no]++;
		down(no, s, e);
		return tree[no];
	}
	int mid = (s + e) / 2;
	int a = upd(no * 2, s, mid, l, r);
	int b = upd(no * 2 + 1, mid + 1, e, l, r);
	return tree[no] = a + b;
}


int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n;

	cin >> m;
	int cmd, a, b, c;

	while (m--) {

		cin >> cmd;
		if (cmd == 0) {
			cin >> a >> b;
			upd(1, 1, n, a, b);
		}
		else {
			cin >> a >> b;
			cout << query(1, 1, n , a, b) << "\n";

		}
	}
}
