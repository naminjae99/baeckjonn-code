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
#include<map>
#include<iomanip>
#include<array>
using namespace std;
using ll = long long;


int n, m, k, t;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int tra[100001];
array<int,3> price[100001];

int tree[400004];
int lazy[400004];
void down(int no, int s, int e) {
	if (lazy[no]) {
		tree[no] += lazy[no];
		if (s != e) {
			lazy[no * 2] += lazy[no];
			lazy[no * 2 + 1] += lazy[no];
		}
		lazy[no] = 0;
	}
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
	int mid = (s + e) >> 1;
	int a = upd(no*2, s, mid, l, r);
	int b = upd(no*2+ 1, mid + 1, e, l, r);
	return tree[no] = a + b;
}

int query(int no, int s, int e, int idx) {
	down(no, s, e);
	if (e < idx || idx < s)
		return 0;
	if (s==e) 
		return tree[no];
	
	int mid = (s + e) >> 1;
	int a = query(no*2, s, mid, idx);
	int b =	query(no*2+1, mid + 1, e, idx);
	return a + b;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n>>m;
	for (int i = 1; i <= m; i++)
		cin >> tra[i];
	for (int i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;

		price[i] = { a,b,c };
	}
	for (int i = 1; i < m; i++) {
		int a = tra[i];
		int b = tra[i + 1];
		if (a < b) {
			upd(1, 1, n, a, b - 1);
		}
		else
			upd(1, 1, n, b, a - 1);
	}
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		int cnt = query(1, 1, n, i);
	//	cout << i<<": "<<cnt << "\n";
		int a = cnt * price[i][0];
		int b = price[i][2] + price[i][1] * cnt;
		if (a > b) {
			sum += b;
		}
		else
			sum += a;
	}
	cout << sum;
}
