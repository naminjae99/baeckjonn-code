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


int t, n;
int par[20001];
int dis[20001];
int lazy[20001];

int find(int x) {
	if (par[x]== x)
		return x ;
	int p = find(par[x]);
	dis[x] += dis[par[x]];
	par[x] = p;
	return p;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;

	char cmd;
	int a, b;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n;
		for (int i = 1; i <= n; i++) {
			par[i] = i;
			dis[i] = lazy[i] = 0;
		}
	
		while (1) {
			cin >> cmd;
			if (cmd == 'O')
				break;
			if (cmd == 'E') {
				cin >> a;
				find(a);
				cout << dis[a]<<"\n";
			}
			else {
				cin >> a >> b;
				par[a] = b;
				dis[a] = abs(a - b) % 1000;
			}
		}
	}
}