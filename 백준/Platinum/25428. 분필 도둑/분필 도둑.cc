#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <string.h>
#include <set>
#include <iomanip>
#include <unordered_set>
#include <map>
#include<cfloat>
#include<sstream>
#include<numeric>
#include <limits>
using namespace std;
using ll = long long;



int n, m, k;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int par[100005];
struct node {
	int a, b, mn;
	bool operator<(const node& o)const {
		return mn > o.mn;
	}
};
vector<node> v;


int find(int x) {
	if (par[x] < 0)
		return x;
	return par[x] = find(par[x]);
}
void uni(int a, int b) {
	a = find(a);
	b = find(b);

	par[a] += par[b];
	par[b] = a;
}
bool chk(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return 1;
	return 0;
}
int cnt[100005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;


	int maxi = -1;
	int root = -1;

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		cnt[i] = x;
		par[i] = -1;

		if (x > maxi){
			maxi = x;
			root = i;
		}
	}


	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a,b,min(cnt[a],cnt[b]) });
	}

	sort(v.begin(), v.end());

	int mx = maxi;
	
	for (auto c : v) {
		int a = c.a;
		int b = c.b;
		int mn = c.mn;
		uni(a, b);
		
	//	cout << a << "랑 " << b << "연결하는 거 확인\n";

		//이미 루트랑 같은 묶음이면
		if (chk(root, a)) {
			mx = max(-par[find(root)] * mn, mx);
		//cout << "같은 묶음이라: " << -par[find(root)] * mn << "\n";
		}
		else {
		//	cout << "다른 묶음이라: " << -par[find(a)] * mn << "\n";
			if (-par[find(a)] * mn > mx) {
				mx = -par[find(a)] * mn;
				root = find(a);
			}

		}

	}
	cout << mx;
}


