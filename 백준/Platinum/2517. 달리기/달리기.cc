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


int n, m,k,t;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int dist[500005];
unordered_map<int, int> mp;
int idx = 1;
int tree[2000005];
int upd(int no, int s, int e, int idx) {
	if (e < idx || idx < s)
		return tree[no];
	if (s == e) {
		return tree[no]+=1;
	}
	int mid = (s + e) / 2;
	int a = upd(no * 2, s, mid, idx);
	int b = upd(no * 2 + 1, mid + 1, e, idx);
	return tree[no] = a + b;
}
int query(int no, int s, int e, int l, int r) {
	if (e < l || r < s)
		return 0;
	if (l <= s && e <= r)
		return tree[no];
	int mid = (s + e) / 2;
	int a = query(no * 2, s, mid, l, r);
	int b = query(no * 2 + 1, mid + 1, e, l, r);
	return a + b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	vector<int> tmp(n);
	//i등으로 들어온 사람의 실력 dist
	for (int i = 0; i < n; i++) {
		cin >> dist[i];
		tmp[i]=dist[i];
	}
	sort(tmp.begin(), tmp.end());
	
	for (int i = 0; i < n; i++) {
		int chk=lower_bound(tmp.begin(),tmp.end(),dist[i])-tmp.begin()+1;
		int left = query(1, 1, n, 1, chk);
		//cout << "1 부터" << dist[i] << "(" << chk << ")" << "의 왼쪽에는" << left << "개 있음\n";
		cout << i+1 - left << "\n";
		upd(1, 1, n, chk);
	}
}
