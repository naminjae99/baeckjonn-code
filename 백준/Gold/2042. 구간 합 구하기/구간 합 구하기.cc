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
#include<iomanip>
#include<deque>
using namespace std;
using ll = long long;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { 1,0,-1,0 };

int n, m, t, ret, h, k;


ll arr[1000005];


ll sum[1005];
void upd(int idx, ll x) {
	int nn = idx / 1000;
	sum[nn] -= arr[idx];
	arr[idx] = x;
	sum[nn] += arr[idx];
}
ll query(int x, int y) {
	int xx = x / 1000;
	int yy = y / 1000;

	ll re = 0;
	if (xx == yy) {
		for (int i = x; i <= y; i++)
			re+=arr[i];
		return re;
	}

	for (int i = x ;i <(xx+1)*1000; i++)
		re += arr[i];
	for (int i = xx+1; i < yy; i++)
		re += sum[i];
	for (int i = yy * 1000; i <= y; i++)
		re += arr[i];
	return re;

}
void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	int nn = n / 1000;
	for (int i = 0; i < nn; i++) {
		int st = i * 1000;
		int en = i * 1000 + 1000;
		for (int j = st; j < en; j++) {
			sum[i] += arr[j];
		}
	}
	for (int j = nn * 1000; j < n; j++)
		sum[nn] += arr[j];


	m += k;
	while (m--) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		if (a == 1) {
			upd(b-1, c);
		}
		else {
			cout<<query(b-1,c-1)<<"\n";
		}
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	
	input();
}
