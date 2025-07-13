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

ll tree[400005];
ll lazy[400005];
ll lazyd[400005];

ll build(int no, int s, int e) {
	if (s == e)
		return tree[no] = arr[s];

	int mid = (s + e) / 2;
	return tree[no] = build(no * 2, s, mid) +build(no * 2 + 1, mid + 1, e);
}
void down(int no, int s, int e) {
	if (lazy[no]!=0||lazyd[no]!=0) {
		ll mid = (s + e) / 2;
		ll left = mid - (ll)s + 1;

		ll inc = lazyd[no];
		ll a = lazy[no];

		if (s != e) {
			lazy[no * 2] +=a;
			lazyd[no * 2]+=inc;

			lazy[no * 2 + 1] +=a+left*inc;
			lazyd[no * 2 + 1] +=inc;
		}
		ll len = (e-s+1);
		tree[no] += (a * len + len * (len - 1)*inc / 2);
		lazy[no]=lazyd[no]=0;
	}
}

ll query(int no, int s, int e, int x) {
	down(no, s, e);
	if (e < x || x < s)
		return 0;
	if (s == e)
		return tree[no];

	int mid = (s + e) / 2;
	return query(no * 2, s, mid, x) + query(no * 2 + 1, mid + 1, e, x);
}
ll upd(int no, int s, int e, int l, int r) {
	down(no, s, e);
	if (e < l || r < s)
		return tree[no];
	if (l <= s && e <= r) {
		lazyd[no]+=1;
		lazy[no]+=(ll)s-(ll)l+1;
		//cout << s << "," << e << "에" << id-1 << "추가\n";
		down(no, s, e);
		return tree[no];
	}
	int mid = (s + e) / 2;
	return tree[no] = upd(no * 2, s, mid, l, r) + upd(no * 2 + 1, mid + 1, e, l, r);
}


int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	build(1, 1, n);
	cin >> m;
	int cmd, a, b, c;

	while (m--) {

		cin >> cmd;
		if (cmd == 1) {
			cin >> a >> b;
			upd(1, 1, n, a, b);
		}
		else {
			cin >> a;
			cout << query(1, 1, n, a) << "\n";

		}
	}
}
