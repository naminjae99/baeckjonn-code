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

using namespace std;
using ll = long long;


int t, n,m;
ll tree[4000004];

ll upd(int no, int s, int e, int idx, int x) {
	if (idx < s || e < idx)
		return tree[no];
	if (s == e)
		return tree[no]+=x;
	int mid = (s + e) / 2;
	ll a = upd(no * 2, s, mid, idx, x);
	ll b = upd(2 * no + 1, mid + 1, e, idx, x);
	return tree[no] = a + b;
}
ll query(int no, int s, int e, int l, int r) {
	if (e < l || r < s)
		return 0;
	if (l <= s && e <= r)
		return tree[no];
	int mid = (s + e) / 2;
	ll a = query(no * 2, s, mid, l,r);
	ll b = query(2 * no + 1, mid + 1, e,l,r);
	return a + b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	ll c, a, b;
	
	while (m--) {
		cin >> c >> a >> b;
		if (c == 1) {
			upd(1, 1, n, a, b);
		}
		else {
			cout<<query(1, 1, n, a, b)<<"\n";
		}
	}
}