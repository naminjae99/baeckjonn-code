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


int t, n, m;
ll tree[800008];
ll cnt[800008];


//삭제쿼리임
pair<ll, ll> upd(int no, int s, int e, ll idx) {
	if (idx < s || e < idx)
		return { tree[no],cnt[no] };
	if (s == e) {

		return { tree[no] += idx,cnt[no] += 1 };
	}
	int mid = (s + e) / 2;
	pair<ll, ll> a = upd(no * 2, s, mid, idx);
	pair<ll, ll> b = upd(2 * no + 1, mid + 1, e, idx);
	tree[no] = { a.first + b.first };
	cnt[no] = a.second + b.second;
	return { tree[no],cnt[no] };
}

pair<ll, ll> query(int no, int s, int e, int l, int r) {
	if (e < l || r < s)
		return { 0,0 };
	if (l <= s && e <= r)
		return { tree[no],cnt[no] };
	int mid = (s + e) / 2;
	pair<ll, ll> a = query(no * 2, s, mid, l, r);
	pair<ll, ll> b = query(2 * no + 1, mid + 1, e, l, r);
	return {a.first+b.first,a.second+b.second};
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	
	ll x;

	ll sum = 1;
	

	for (int i = 1; i <= n; i++) {
		cin >> x;
		
		if (i == 1) {
			upd(1, 0, 200000, x);

			continue;
		}
		

		ll tmp = 0;
		if (x != 0) {
			pair<ll, ll> le = query(1, 0, 200000, 0, x - 1);
			tmp += le.second*x - le.first;
		}
		
		if (x < 200000) {
			pair<ll, ll> ri = query(1, 0, 200000, x + 1, 200000);
			tmp += ri.first - x * ri.second;
		}
/*

		cout << x << "\n";
		cout << le.first << ", " << le.second << "\n";
		cout << ri.first << ", " << ri.second << "\n";

		cout << tmp << "\n\n\n";*/

		sum = ((sum% (ll)1000000007)*(tmp% (ll)1000000007));
		sum =sum% (ll)1000000007;
	
		upd(1, 0, 200000, x);

	}

	
		//cout << sum;
	
	cout << sum % (ll)1000000007;
	return 0;

}