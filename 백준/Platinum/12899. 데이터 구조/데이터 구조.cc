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
using namespace std;
using ll = long long;

int n, m, k, t;
int tree[8000008];

void upd(int no, int s, int e, int idx,int x) {
	if (e < idx || idx < s)
		return;
	if (s == e) {
		tree[no]+=x;
		return;
	}
	int mid = (s + e) / 2;
	upd(no * 2, s, mid, idx,x);
	upd(no * 2 + 1, mid + 1, e, idx,x);
	tree[no] = tree[no * 2] + tree[no * 2 + 1];
}
int ret;
void query(int no,int s,int e,int x) {
	if (s == e) {
		ret = s;
		tree[no]--;
		return;
	}
	int left = tree[no * 2];
	int mid = (s + e) / 2;

	if (x<=left) {
		query(no*2, s, mid, x);
	}
	else {
		//왼쪽구간은 left 개있으니깐
		//오른쪽구간에서 x-left개 찾기
		query(no * 2 + 1, mid + 1, e, x - left);
	}
	tree[no] = tree[no * 2] + tree[no * 2 + 1];

}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n ;
	int a, b;
	while (n--) {
		cin >> a >> b;
		if (a == 1) {
			upd(1, 1, 2000000, b,1);
		}
		else {
			query(1, 1, 2000000, b);
			cout<<ret<<"\n";
//			upd(1, 1, 2000000, ret, -1);

		}
	}
}
