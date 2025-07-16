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

int chk[4000005];
int idx[4000005];


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
	par[b] += par[a];
	par[a] = b;
}

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n >> m >> k;
	int x;

	for (int i = 1; i <= m; i++) {
		cin >> x;
		chk[x]++;
	}
	for (int i = 1; i <= n; i++) {
		idx[i] = i + 1;
		par[i] = -1;
	}

	for (int i = 1; i <= k; i++) {
		cin >> x;
		//cout << x << "차례\n";
		int index = idx[x];
		//cout << "index: " << index << "\n";
		
		if (chk[index]>0) {
			cout << index << "\n";
			chk[index]--;
			uni(x, index);
		}
		else {
			int p = find(x);
			int pidx = idx[p];

			while (1) {
				if (chk[pidx] > 0)
					break;
				uni(p, pidx);
				p = pidx;
				pidx = idx[p];
			}
			cout << pidx << "\n";
			chk[pidx]--;
			uni(p, pidx);
		}
	}
	
}
