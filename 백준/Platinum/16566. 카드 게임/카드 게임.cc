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

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, ret, t, k, Q, L;



bool vis[4000005];
int par[4000005];

int find(int x) {
	if (par[x] == x)
		return x;
	return par[x] = find(par[x]);
}
void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	par[a] = b;
}
void init() {
	cin >> n >> m >> k;


	int x;
	for (int i = 0; i < m; i++) {
		cin >> x;
		vis[x] = 1;
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i])
			par[i] = i;
		else
			par[i] = i + 1;
	}


	for (int i = 0; i < k; i++) {
		cin >> x;
		x = find(x + 1);
		cout << x<<"\n";
		uni(x, x + 1);

	}


}

int main() {
	fastio
		init();
}