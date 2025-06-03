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
using namespace std;
using ll=long long ;
ll n, k, m;
ll arr[1000001];
ll tree[4000004];
int i;	
ll  init(int N, int st, int en) {
	if (st == en) {
		return	tree[N] = arr[st];
	}
	int mid = (st + en) / 2;
	ll a=	init(2 * N, st, mid);
	ll b=init(2 * N + 1, mid + 1, en);
	tree[N] = a+b;
	return tree[N];
}
ll query(int N,int st,int en,int l,int r) {
	if (st > r || en < l)
		return 0;
	if (st >= l && en <= r) {
		return tree[N];
	}
	int mid = (st + en) / 2;
	ll a=query(2 * N, st, mid,l,r);
	ll b=query(2 * N + 1, mid + 1, en,l,r);
	return a + b;
}
void update(int N, int st, int en, int x, ll val) {
	if (st > x || en < x)
		return;
	if (st == en) {
		tree[N] += val;
		return;
	}
	int mid = (st + en) / 2;
	update(2 * N, st, mid, x, val);
	update(2 * N + 1, mid + 1, en, x, val);
	tree[N] = tree[2 * N]+ tree[N * 2 + 1] ;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> k;
	for (i = 1; i <= n; i++)
		cin >> arr[i];
	init(1, 1, n);

	ll cmd,a,b;
	for (i = 0; i < m + k; i++) {
		cin >> cmd >> a >> b;
		if (cmd == 1) {
			ll dif = b-arr[a];
			arr[a] = b;
			update(1, 1, n, a, dif);
			
		}
		else {
			cout << query(1, 1, n, a, b)<<"\n";
		}
	}
}