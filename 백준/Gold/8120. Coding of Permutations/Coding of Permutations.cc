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
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;

int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, ret, k, t, Q, p;

vector<int>a;
vector<int>b;
vector<int>tree;

int st;

//구간합이 3이되는 인덱스
int query(int x) {
	int idx = 1;
	while (idx <= st) {
		if (tree[idx << 1] >= x)
			idx = idx << 1;
		else {
			x-= tree[idx << 1];
			idx = idx << 1 | 1;
		}
	}
	return idx - st; // 실제 값 반환
}

void upd(int idx,int x) {
	 int i=idx + st;
	while (i) {
		tree[i]+=x;
		i /= 2;
	}
}
void input() {
	cin >> n;

	// n보다 같거나 큰 젤 작은 2의 거듭제곱수 찾기
	for (st = 1; st < n; st <<= 1)
		1;

	tree.assign(st * 2, 0);
	st--;

	a.resize(1+n);
	b.resize(n+1);

	// 모든 수가 살아있다고 세팅
	for (int i = 1; i <= n; i++) {
		upd(i, 1);
		cin >> b[i];
	}

	

	for (int i = n; i >= 1; i--) {
	
		if (b[i] >= i) {
			cout << "NIE";
			return;
		}
	
		int x=query(tree[1] - b[i]);
	

		a[i] = x;
		upd(x, -1);
	}

	
	for (int i = 1; i <= n; i++) {
		cout << a[i] << "\n";
	}
}


void solve() {

}
int main() {
	fastio;
	input();
	solve();

}


