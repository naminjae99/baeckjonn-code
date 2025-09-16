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
#include<array>
#include<limits.h>
#include<cfloat>
using namespace std;
using ll = long long;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int n, t, ret, m;
int tree[4000005];

int query(int no, int s, int e,int x) {
	if (s == e)
		return s;

	int mid = (s + e) / 2;
	int left = tree[no * 2];

	if (left >= x)
		return query(no * 2, s, mid, x);
	return query(no * 2+1, mid + 1, e, x - left);
	
}
void upd(int no, int s, int e, int idx, int x) {
	if (e < idx || idx < s)
		return ;

	tree[no] += x;
	if (s == e) 
		return ;
	

	int mid = (s + e) / 2;
	upd(no * 2, s, mid, idx, x);
	upd(no * 2 + 1, mid + 1, e, idx, x);
//	tree[no] = tree[no * 2] + tree[no * 2 + 1];
}
void input() {
	cin >> n;
	while (n--) {
		int cmd,a,b;
		cin >> cmd;
		if (cmd == 1) {
			cin >> a;
			int idx=query(1, 1, 1000000, a);
			cout << idx<<"\n";
			upd(1, 1, 1000000, idx, -1);
		}
		else {
			cin >> a >> b;
			upd(1, 1, 1000000, a, b);
		}
	}
}
void solve() {


}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	input();
	solve();


	//cout << ret;

}
