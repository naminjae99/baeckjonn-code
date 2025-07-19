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
using namespace std;
using ll = long long;

vector<int> ed[100005];
int n, m;

ll arr[1000005];
ll st, en;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n>>m;

	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		
		en = max(en,x);
		arr[i] = x;
	}
	ll mid = 0;
	while (st < en) {
		mid = (st + en+1) >> 1;
		ll sum = 0;
		ll dif;
		for (int i = 0; i < n; i++) {
			dif = arr[i] - mid;
			if (dif> 0) {
				sum += dif;
			}
		}
		if (sum >= m) {
			st = mid;
		}
		else {
			en = mid-1;
		}
	}
	cout << st;
}
