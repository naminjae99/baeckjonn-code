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
using namespace std;
using ll = long long;


int n,m,k;

int par[100005];
int ch[100005][2];
int cnt;

int last;
bool flag;

void f(int x) {


	int lc = ch[x][0];
	int rc = ch[x][1];

	if (flag)
		return;

	//cout << x << "< " << cnt << "\n";
	
	
	if (lc != 0) {
		cnt++;
		f(lc);
		if (flag)
			return;
		cnt++;
	}
	if (rc != 0 ) {
		cnt++;
		f(rc);
		if (flag)
			return;
		cnt++;
	}
	
	if (x == last) {
		flag = 1;
		return;
	}

	
}
void find_last(int x) {
	int lc = ch[x][0];
	int rc = ch[x][1];
	
	//cout << x << " , " << last << "\n";
	if (lc != 0) {
		last = lc;
		find_last(lc);
	}
	last = x;
	if (rc != 0) {
		last = rc;
		find_last(rc);
	}
}
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	
	cin >> n;

	while (n--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (b != -1) {
			ch[a][0] = b;
			par[b] = a;
		}
		if (c != -1) {
			ch[a][1] = c;
			par[c] = a;
		}
	}

	find_last(1);
	//cout << last << ": last\n";
	f(1);
	cout << cnt;
}
