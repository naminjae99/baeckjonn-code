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
#include<iomanip>
using namespace std;
using ll = long long;



int t, n, m;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
ll arr[100005];
ll tree[400005];
ll lazyadd[400005];
ll lazygop[400005];
ll lazy[400005];

const ll mx = 1e9 + 7;


void down(int no, int s, int e) {
	int l = no * 2;
	int r = no * 2 + 1;

	if (lazyadd[no]!=0||lazygop[no]!=1) {

		tree[no] =(tree[no]* lazygop[no])%mx;
		tree[no] = (tree[no] + (e - s + 1)*lazyadd[no]) % mx;
		if (s != e) {

			lazygop[l] = (lazygop[l]*lazygop[no])%mx;
			lazygop[r] = (lazygop[r] * lazygop[no]) % mx;

			lazyadd[l] = (lazygop[no]*lazyadd[l]+lazyadd[no])%mx;
			lazyadd[r] = (lazygop[no] * lazyadd[r]+ lazyadd[no])%mx;
		}
		lazygop[no] = 1;
		lazyadd[no] = 0;
	}
}


ll build(int no, int s, int e) {
	if (s == e)
		return tree[no] = arr[s]%mx;
	int mid = (s + e) / 2;
	ll a = build(2 * no, s, mid);
	ll b = build(2 * no + 1, mid + 1, e);
	return tree[no] = (a + b)%mx;
}
ll query(int no, int s, int e, int l, int r) {
	down(no, s, e);

	if (e < l || r < s)
		return 0;
	if (l <= s && e <= r)
		return tree[no]%mx;
	int mid = (s + e) / 2;
	ll a = query(no * 2, s, mid, l, r);
	ll b = query(no * 2 + 1, mid + 1, e, l, r);
	return (a + b)%mx;
}
ll upd(int no, int s, int e, int l, int r,ll ad,ll go) {
	down(no, s, e);

	if (e < l || r < s)
		return tree[no]%mx;
	if (l <= s && e <= r) {
		lazyadd[no] = (go * lazyadd[no] + ad)%mx;
		lazygop[no] = (lazygop[no] * go)%mx;
		down(no, s, e);
		return tree[no]%mx;
	}
	int mid = (s + e) / 2;
	ll a = upd(no * 2, s, mid, l, r,ad,go);
	ll b = upd(no * 2 + 1, mid + 1, e, l, r,ad,go);
	return tree[no]=(a + b) % mx;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	
	cin >> n;
	fill(lazygop,lazygop+400005, (ll)1);
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	build(1, 1, n);
	cin >> m;

	int  cmd, a, b;
	ll c;
	while (m--) {
		cin >> cmd;
		if (cmd == 1) {
			cin >> a >> b >> c;
			upd(1, 1, n, a, b, c,1 );
		}
		else if (cmd == 2) {
			cin >> a >> b >> c;
			upd(1, 1, n, a, b, 0, c);
		}
		else if (cmd == 3) {
			cin >> a >> b >> c;
			upd(1, 1, n, a, b, c, 0);
		}
		else {
			cin >> a >> b;
			cout<<query(1, 1, n, a, b)<<"\n";
		}
	}
}
