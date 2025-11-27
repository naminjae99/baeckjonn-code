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


int tree[100005];

int re[100005];
void upd(int i, int x) {
	while (i <= n) {
		tree[i] += x;
		i += (i&-i);
	}
}
int kth(int x) {
	int i = 0;
	int b = 1 << 18;
	while (b) {
		int nxt = i + b;
		if (nxt <= n && tree[nxt] < x) {
			x -= tree[nxt];
			i = nxt;
		}
		b >>= 1;
	}
	return i + 1;
}

void input() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		upd(i, 1);
}

	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		//합이 x+1인 인덱스 반환하기
		int idx = kth(x+1);
	
		re[idx] = i;
		upd(idx,-1);
	}
	for (int i = 1; i <= n; i++)
		cout << re[i] << "\n";
}
void solve() {



}

int main() {
	fastio;
	input();
	solve();
}











