#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <string>
#include <string.h>
#include<iomanip>
#include<limits>
#include<cfloat>
using namespace std;
using ll = long long;
using ld = long double;
int t, Q, n, m, p;

int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };


vector<int> tree;

void upd(int no, int s, int e, int idx) {
	if (e < idx || idx < s)
		return;
	if (s == e) {
		tree[no]++;
		return;
	}
	int mid = (s + e) >> 1;
	upd(no * 2, s, mid, idx);
	upd(no * 2 + 1, mid + 1, e, idx);
	tree[no] = tree[no*2]+tree[no*2+1];
}
int query(int no, int s, int e, int l, int r) {
	if (e < l || r < s)
		return 0;
	if (l <= s && e <= r)
		return tree[no];
	int mid = (s + e) >> 1;
	int a = query(no * 2, s, mid, l, r);
	int b = query(no * 2 + 1, mid + 1, e, l, r);
	return a + b;
}


vector<pair<int, int>>v;
bool cmp(pair<int, int>a, pair<int, int> b) {
	if (a.first != b.first)
		return a.first < b.first;
	return a.second > b.second;
}
struct f {
	int y, x, idx;
};
bool fcmp(f a, f b) {
	if (a.y != b.y)
		return a.y < b.y;
	return a.x > b.x;
}
vector<f>vv;

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		v.clear();
		vv.clear();
		tree.assign(n * 4, 0);
		for (int i = 0; i < n; i++) {
			int x, y;
			cin >> x >> y;
			v.push_back({ x,y });
		}
		sort(v.begin(), v.end(), cmp);

		for (int i = 0; i < v.size(); i++) {
			vv.push_back({ v[i].second,v[i].first,i });
		}
		sort(vv.begin(), vv.end(), fcmp);

		ll sum = 0;
		for (auto c : vv) {

			sum += (ll)query(1, 0, n - 1, c.idx, n - 1);
			upd(1, 0, n - 1, c.idx);
		}
		cout << sum << "\n";
	}

}