#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <memory.h>
#include <algorithm>
#include <math.h>
#include <queue>
#include <unordered_set>
#include <string>
#include <string.h>
#include<iomanip>
#include<limits>
#include<cfloat>
using namespace std;
using ll = long long;
using ld = long double;
int t, Q, n, p;

int dx[8] = { -1, 1, 0, 0, -1, -1, 1, 1 };
int dy[8] = { 0, 0, -1, 1, -1, 1, -1, 1 };


unordered_map<ll,ll>mp;
ll m;
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	ll count = 0;
	ll total = 0;
	ll x;
	mp[0]++;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		total += x;
		
		count += mp[total - m];
		mp[total]++;
	}
	cout << count;
}