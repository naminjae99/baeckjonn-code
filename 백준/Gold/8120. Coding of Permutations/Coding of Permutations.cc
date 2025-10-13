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


int a[30005];
int b[30005];
int tree[122222];
int build(int node, int s, int e) {
	if (s == e)
		return tree[node] = 1;
	int mid = (s + e) >> 1;
	int a = build(node * 2, s, mid);
	int b = build(node * 2 + 1, mid + 1, e);
	return tree[node] = a + b;
}
//왼쪽에서 합이 x인 인덱스 반환
int query(int node, int s, int e, int x) {
	if (s == e)
		return s;

	int left = tree[node * 2];
	int mid = (s + e) >> 1;

	//cout << s << "," << e << "에서 왼쪽 자식" << left << "개" << "찾아야하는건 " << x << "개\n";

	if (left >= x) 
		return query(node * 2, s, mid, x);
	return query(node * 2 + 1, mid + 1, e, x-left);
}

int upd(int node, int s, int e, int idx) {
	if (e < idx || idx < s)
		return tree[node];
	if (s == e) 
		return tree[node]=0;
	int mid = (s + e) >> 1;
	int a = upd(node * 2, s, mid, idx);
	int b = upd(node * 2 + 1, mid + 1, e, idx);
	return tree[node] = a + b;
}
void input() {
	cin >> n;
	build(1, 1, n);
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
		if (b[i] >= i) {
			cout << "NIE";
			return;
		}
	}
	stack<int> ss;
	for (int i = n; i >=1; i--) {
		//자기보다 앞에 i-1개가 있는데 자기보다 큰건b cnt개가 있어야함
		int bcnt = b[i];
		//cout << i << "는" << tree[1] << "개 중에서 자기보다 큰게" << b[i] << "개 여야함\n";
		//cout << "즉 " << tree[1] - b[i] << "번 원소 찾기\n";
		int x=query(1, 1, n, tree[1]- bcnt);
		//cout << x << "\n\n";
		ss.push(x);
		upd(1, 1, n, x);

	
	}
	while(!ss.empty()){
		cout << ss.top()<<"\n";
		ss.pop();
	}
}


void solve() {

}
int main() {
	fastio;
	input();
	solve();

}


