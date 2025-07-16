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


int n, m, k,t;

bool chk[4000005];


int par[4000005];

int find(int x) {
	if (par[x] < 0)
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

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n >> m >> k;
	int x;

	for (int i = 1; i <= m; i++) {
		cin >> x;
		chk[x]=1;
	}
	memset(par, -1, sizeof(par));

	for (int i = 1; i <= k; i++) {
		cin >> x;
		

		int mn = find(x + 1);
		while (!chk[mn]) {
			uni(mn, mn + 1);
			mn = mn + 1;
		}

		cout << mn << "\n";
		uni(mn, mn+1);
	}
	
}
