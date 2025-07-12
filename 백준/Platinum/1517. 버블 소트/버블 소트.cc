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


int n, m, k,t;
vector<pair<int,int>> arr;
int tree[2000005];
unordered_map<int, int> mp;

int query(int no, int s, int e,int l,int r) {
	if (e < l || r < s)
		return 0;
	if (l <= s && e <= r)
		return tree[no];
	int mid = (s + e) / 2;
	int a = query(no * 2, s, mid, l, r);
	int b = query(no * 2 + 1, mid + 1, e, l, r);
	return a + b;
}

int upd(int no, int s, int e, int idx) {
	if (e < idx || idx < s)
		return tree[no];
	if (s == e)
		return tree[no] = 1;
	int mid = (s + e) / 2;
	int a = upd(no * 2, s, mid, idx);
	int b = upd(no * 2 + 1, mid + 1, e, idx);
	return tree[no] = a + b;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n;
	int x;
	arr.push_back({ -1,-1 });

	for (int i = 1; i <=n; i++) {
		cin >> x;
		arr.push_back({ x,i });
	}
	sort(arr.begin(), arr.end());
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = query(1, 1, n, arr[i].second + 1, n);
		sum += (ll)cnt;
		upd(1, 1, n, arr[i].second);
	}
	cout << sum;
}
