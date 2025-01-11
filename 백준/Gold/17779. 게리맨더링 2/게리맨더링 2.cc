#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include<iostream>
#include <string>
#include<deque>
#include <memory.h>
#include<vector>
#include<set>
#include<queue>
#include <cassert>
#include<algorithm>

using namespace std;

int arr[21][21];
int n;
int val[5];
int re = 987654321;
void cal() {
	int x = val[2];
	int y = val[3];
	int d1 = val[0];
	int d2 = val[1];

	int tmp[21][21] = { 0 };
	
	

	for (int i = 0; i <= d1; i++) {
		tmp[x + i][y - i] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		tmp[x + i][y + i] = 5;
	}
	for (int i = 0; i <= d2; i++) {
		tmp[x +d1+ i][y-d1 + i] = 5;
	}
	for (int i = 0; i <= d1; i++) {
		tmp[x +d2+ i][y+d2 - i] = 5;
	}
	for (int i = 1; i <= n; i++) {
		int count = 0;
		int y1, y2;
		for (int j = 1; j <= n; j++) {
			if (tmp[i][j] == 5) {
				count++;
				if (count == 1)
					y1 = j;
				else
					y2 = j;
			}
		}
		if (count == 2) {
			for (int j = y1 + 1; j < y2; j++) {
				tmp[i][j] = 5;
			}
		}
	}
	for (int i = 1; i <x+d1; i++) {
		for (int j = 1; j <= y; j++) {
			if (tmp[i][j] == 5)
				break;
			tmp[i][j] = 1;
		}
	}
	for (int i = 1; i <=x + d2; i++) {
		for (int j = n; j  > y; j--) {
			if (tmp[i][j] == 5)
				break;
			tmp[i][j] = 2;
		}
	}
	for (int i = x+d1; i <=n; i++) {
		for (int j = 1; j < y-d1+d2; j++) {
			if (tmp[i][j] == 5)
				break;
			tmp[i][j] = 3;
		}
	}
	for (int i = x+d2+1; i <= n; i++) {
		for (int j = n; j >=y-d1+d2; j--) {
			if (tmp[i][j] == 5)
				break;
			tmp[i][j] = 4;
		}
	}

	int cnt[6] = { 0, };
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt[tmp[i][j]] += arr[i][j];
		}
	}




	/*
	9
100 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 100
*/

	for (int i = 1; i <= 5; i++) {
		if (cnt[i] == 0)
			return;
	}
	
	int ll = cnt[1];
	int ss = cnt[1];
	ll = max(ll, cnt[2]);
	ll = max(ll, cnt[3]);
	ll = max(ll, cnt[4]);
	ll = max(ll, cnt[5]);
	ss = min(ss, cnt[2]);
	ss = min(ss, cnt[3]); 
	ss = min(ss, cnt[4]);
	ss = min(ss, cnt[5]);

	re = min(re, ll - ss);

}
void f(int dep) {
	if (dep == 4) {
		if (val[0] + val[1] + val[2] > n)
			return;
		if (val[3] - val[0]<1 || val[3] + val[1]>n)
			return;
		
		cal();
		return;
	}
	for (int i = 1; i <= n; i++) {
		val[dep] = i;
		f(dep + 1);
	}
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> arr[i][j];
	f(0);
	cout << re;
}