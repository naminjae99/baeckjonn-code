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
#include<cfloat>
#include<array>
using namespace std;
using ll = long long;


int n, m, k, t;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


void query(int no, int s, int e) {
	
}
int par[100005];
int cnt[100005];

int find(int x) {
	if (par[x] ==x)
		return x;
	int pa = find(par[x]);
	//cout << x << "의 루트 부모: " << pa << "\n";
	cnt[x] += cnt[par[x]];
	//cout << x << "의 무게" << cnt[x] << "+" << cnt[par[x]] << "\n";
	return par[x]=pa;
}

void uni(int a, int b, int c) {
	int fa = find(a);
	int fb = find(b);
	if (fa == fb)
		return;
	
	cnt[fb] = -cnt[b] + cnt[a] + c;
	par[fb] = fa;
}
 int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (1) {
		cin >> n >> m;
		if (!n && !m)
			break;

		// 초기화
		for (int i = 1; i <= n; i++) {
			par[i] = i;
			cnt[i] = 0;
		}

		char cmd;
		int a, b;
		ll c;
		while (m--) {
			cin >> cmd;
			if (cmd == '!') {
				cin >> a >> b >> c;
				uni(a, b, c);
			

			}
			else {
				cin >> a >> b;
				if (find(a) != find(b))
					cout << "UNKNOWN\n";
				else {
					cout<<cnt[b] - cnt[a] << "\n";
				}
			}
		}

	}
}
