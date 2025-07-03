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

struct f {
	int mx, mn;
};
int t, n, m;
f tree[400008];

f gf(f a, f b) {
	f tmp;
	if (a.mx > b.mx)
		tmp.mx = a.mx;
	else
		tmp.mx = b.mx;

	if (a.mn < b.mn)
		tmp.mn = a.mn;
	else
		tmp.mn = b.mn;
	return tmp;
}
f  init(int no,int s, int e) {
	if (s == e) {
		return tree[no] = { s,s };
	}
	int mid = (s + e) / 2;
	f a=init(no * 2, s, mid);
	f b=init(no * 2 + 1, mid + 1, e);
	return tree[no] =gf(a,b);
}

f query(int no, int s, int e, int l,int r) {
	

	if (s >r || e < l)
		return {-1,987654321};
	if (l <= s && e <= r) {
		return tree[no];
	}
	int mid = (s + e) / 2;
	f a=query(no * 2, s, mid,l,r);
	f b=query(no * 2 + 1, mid + 1, e,l,r);
	return gf(a, b);
}

f  upd(int no, int s, int e, int idx,int x) {
	
	if (s > idx || e < idx)
		return tree[no]; 
	if (s == e) {
		return tree[no] = { x,x};
	}
	int mid = (s + e) / 2;
	f a=upd(no * 2, s, mid, idx,x);
	f b=upd(no * 2 + 1, mid + 1, e, idx,x);
	return tree[no] =gf(a,b);
}

int arr[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;


	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m;
	
		for (int i = 0; i < n; i++)
			arr[i] = i;
		init(1, 0, n-1);
		int c,a,b;
		while (m--) {
			cin >>c>> a >> b;
	
			if (c == 0) {
				//변경
				int x, y;
				x = arr[a];
				y = arr[b];

				//cout << x << ", " << y << "\n";
				upd(1, 0, n-1 , a,y);
				upd(1, 0, n-1 , b, x);

				swap(arr[a], arr[b]);
				//cout << query(1, 0, n - 1, a, a) << ", " << query(1, 0, n - 1, b, b) << "\n\n";


			}
			else {
				int mx = query(1, 0, n-1, a, b).mx;
				int mn = query(1, 0, n - 1, a, b).mn;
				if (a == mn&&b==mx)
					cout << "YES\n";
				else
					cout << "NO\n";
			}
		}
		

	}
	return 0;

}