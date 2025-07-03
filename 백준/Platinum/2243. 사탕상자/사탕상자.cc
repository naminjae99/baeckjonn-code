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

using namespace std;
using ll = long long;

int t, n, m;
int tree[4000008];

int init(int no,int s, int e) {
	if (s == e) {
		return tree[no] = 0;
	}
	int mid = (s + e) / 2;
	int a=init(no * 2, s, mid);
	int b=init(no * 2 + 1, mid + 1, e);
	return tree[no] =(a+b);
}

int query(int no, int s, int e, int cnt) {
	if (s == e)
		return s;
	int mid = (s + e) / 2;
	//왼쪽자식이
	if (tree[no * 2] >= cnt)
		return query(no * 2, s, mid, cnt);
	return query(no * 2+1, mid+1, e, cnt - tree[no * 2]);
}

int upd(int no, int s, int e, int idx,int x) {
	
	if (s > idx || e < idx)
		return tree[no]; 
	if (s == e) {
		return tree[no]+=x;
	}
	int mid = (s + e) / 2;
	int a=upd(no * 2, s, mid, idx,x);
	int b=upd(no * 2 + 1, mid + 1, e, idx,x);
	return tree[no] =(a+b);
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	int a, b, c;
	while (n--) {
		cin >> a;

		//꺼내기
		if (a == 1) {
			cin >> b;
			int idx = query(1, 1, 1000000, b);
			cout << idx<<"\n";
			upd(1, 1, 1000000, idx, -1);
			//arr[idx]--;
		}
		//b맛을 c개넣기
		else {
			cin >> b >> c;
			upd(1, 1, 1000000, b, c);
			//arr[b] += c;
		
		}
	}


	
	return 0;

}