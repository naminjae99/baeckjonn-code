#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<algorithm>
#include<queue>
#include<string>
#include<string.h>

using namespace std;
using ll = long long;

struct f {
	int a, b, c;
	bool operator<(const f& o) const {
		return a < o.a;
	}
};

int n;
int tree[2000008];
vector<f> loc;
const int INF = 1e9;

int query(int no, int s, int e, int l, int r) {
	if (e < l || r < s)
		return INF;
	if (l <= s && e <= r)
		return tree[no];
	int mid = (s + e) / 2;
	int a = query(2 * no, s, mid, l, r);
	int b = query(2 * no + 1, mid + 1, e, l, r);
	return min(a, b);
}

int upd(int no, int s, int e, int idx, int x) {
	if (s > idx || e < idx)
		return tree[no];
	if (s == e)
		return tree[no] = min(tree[no], x);
	int mid = (s + e) / 2;
	int a = upd(no * 2, s, mid, idx, x);
	int b = upd(no * 2 + 1, mid + 1, e, idx, x);
	return tree[no] = min(a, b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	int x;
	loc.resize(n + 1);

	for (int j = 1; j <= n; j++) {
		cin >> x;
		loc[x].a = j;
	}
	for (int j = 1; j <= n; j++) {
		cin >> x;
		loc[x].b = j;
	}
	for (int j = 1; j <= n; j++) {
		cin >> x;
		loc[x].c = j;
	}

	sort(loc.begin() + 1, loc.end());

	fill(tree, tree + 4 * n + 1, INF);

	int re = 0;
	for (int i = 1; i <= n; i++) {
		// loc[i].b보다 작은 등수 중에서 수학 등수가 더 낮은 사람 있는지 확인
		if (query(1, 1, n, 1, loc[i].b - 1) > loc[i].c)
			re++;
		upd(1, 1, n, loc[i].b, loc[i].c);
	}

	cout << re;
	return 0;
}
