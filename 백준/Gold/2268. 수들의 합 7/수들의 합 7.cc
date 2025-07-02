#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include<iomanip>
#include<string>
#include<memory.h>
#include<array>
#include<unordered_map>
#include<algorithm>
#include<set>
#include<sstream>
using namespace std;
using ll = long long;


ll arr[1000001];
ll tree[4000004];
int n, m;




ll query(int no, int s, int e, int l, int r) {
	if (e < l || r < s)
		return 0;

	if (l <= s && e <= r)
		return tree[no];
	int mid = (s + e) / 2;
	ll a = query(no * 2, s, mid,l,r);
	ll b = query(no * 2 + 1, mid + 1, e,l,r);
	return a+b;
}
ll upd(int no, int s, int e, int idx, ll x) {
	if (idx < s || e < idx)
		return tree[no];
	if (s == e) 
		return tree[no] += x;
	
	int mid = (s + e) / 2;
	ll a = upd(no * 2, s, mid, idx, x);
	ll b = upd(no * 2 + 1, mid + 1, e, idx, x);
	return tree[no] =a+b;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;
	

	ll a, b, c;

	cin >> m;
	
	ll dif = 0;


	while (m--) {
		cin >> a >> b>>c;
	
		if (a == 1) {
			dif = c - arr[b];
			arr[b] = c;
			upd(1, 1, n, b, dif);
		}
		else {
		
			if (b > c)
				swap(c, b);
			cout<<query(1, 1, n, b, c)<<"\n";
		}
	
	}
}