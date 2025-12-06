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
#include<deque>
#include<unordered_set>
#include<string>
#include<string.h>
#include<stack>
#include<sstream>
#include<iomanip>
#include<deque>
#include<array>
#include<limits.h>
#include<cfloat>
#include<map>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;

int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int dy[8] = { 1,1,1,0,0,-1,-1,-1 };
int n, m, ret, k, Q, L;

ll val[500005];
vector<int> ed[500005];
int a[500005];
int b[500005];
int idx;

void dfs(int x) {
	a[x] = ++idx;
	
	for (auto c : ed[x]) {
		if (a[c])continue;
		dfs(c);
	}

	b[x] = idx;	
}

int lg = (1<<19);
ll penwick[550005];

void upd(int i, ll x) {
	
	while(i<lg){
		penwick[i] += x;
		i += i & -i;
	}
}
int query(int i) {
	ll re = 0;
	while (i>0) {
		re += penwick[i];
		i -= i & -i;
	}
	return re;
}

void input() {
	cin >> n >> m;
	cin >> val[1];
	for (int i = 2; i <= n; i++) {
		ll x;
		int y;
		cin >> x >> y;
		val[i] = x;
		ed[i].push_back(y);
		ed[y].push_back(i);
	}
	
	
	dfs(1);


	while (m--) {
		char cmd; int x;ll y;
		cin >> cmd;
		if (cmd == 'p') {
			cin >> x >> y;
			
			int st = a[x];
			int en = b[x];
			upd(st + 1, y);
			upd(en + 1, -y);
		}
		else {
			cin >> x;
			cout << query(a[x])+val[x] << "\n";
		}
	}
}
void solve() {



}

int main() {
	fastio;
	input();
	solve();
}




