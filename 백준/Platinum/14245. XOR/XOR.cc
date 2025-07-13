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
int arr[500005];

int tree[2000005];
int lazy[2000005];

void build(int no, int s, int e) {
	if (s == e) {
		tree[no] = arr[s];
		return;
	}
	int mid = (s + e) / 2;
	build(no * 2, s, mid);
	build(no * 2 + 1, mid + 1, e);
}
void down(int no, int s, int e) {
	if (lazy[no]) {
		tree[no] = tree[no]^lazy[no];
		if (s != e) {
			lazy[no * 2] ^= lazy[no];
			lazy[no * 2 + 1] ^= lazy[no];
		}
		lazy[no] = 0;
	}
}
int ret;
void  query(int no, int s, int e, int idx) {
	down(no, s, e);
	if (e < idx || idx < s)
		return;
	if (s == e) {
		ret = tree[no];
		return;
	}
	int mid = (s + e) / 2;
	query(no * 2, s, mid, idx);
	query(no * 2 + 1, mid + 1, e, idx);
}
void upd(int no, int s, int e, int l, int r, int x) {
	down(no, s, e);
	if (e < l || r < s)
		return;
	if (l <= s && e <= r) {
		lazy[no] = x;
		down(no, s, e);
		return;
	}
	int mid = (s + e) / 2;
	upd(no * 2, s, mid, l, r, x);
	upd(no * 2 + 1, mid + 1, e, l, r, x);
}

void p() {

	for (int i = 1; i <= 4 * n; i++) {
		cout << i << " : " << tree[i] <<", "<<lazy[i]<< "\n";
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> m;
	int cmd, a, b, c;
	build(1, 0, n - 1);
	while (m--) {
		//p();
		//cout << "\n\n\n";

		cin >> cmd;
		if (cmd == 1) {
			cin >> a >> b >> c;
			upd(1, 0, n - 1, a, b, c);
		}
		else {
			cin >> a;
			query(1, 0, n - 1, a);
			cout << ret << "\n";
		}
	}
}
