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


const int lg = 1 << 21;
ll ori[500005];
ll des[500005];


void input() {
	ll count = 0;
	cin >> n >> count;
	for (int i = 0; i < n; i++)
		cin >> ori[i];

	for (int i = 0; i < n; i++)
		cin >> des[i];

	ll s = 0;
	ll e = 1e18 + 1e6 + 5;
	ll re, mid;
	ll cnt;

	while (s <= e) {
		mid = (s + e) / 2;

		//mid이상되게 만들기
		ll tmp = 0;
		for (int i = 0; i < n; i++) {
			if (ori[i] >= mid)
				continue;
			tmp += (mid - ori[i] + des[i] - 1) / des[i];
			if (tmp > count)
				break;
		}


		if (tmp > count)
			e = mid - 1;
		else {
			re = mid;
			cnt = tmp;
			s = mid + 1;
		}
	}


	if (cnt == count) {
		for (int i = 0; i < n; i++) {
			if (ori[i] >= re) {
				cout<< ori[i]<<" ";
				
			}
			else {
				cout << ((re - ori[i] + des[i] - 1) / des[i])*des[i] + ori[i]<<" ";
			}
		}
	}
	else {
		ll dif = count - cnt;
		for (int i = 0; i < n; i++) {
			if (ori[i] > re) {
				cout << ori[i] << " ";
			}
			else {
				ll nn = ((re - ori[i] + des[i] - 1) / des[i])*des[i] + ori[i];
				if (nn == re&&dif) {
					cout << nn + des[i] << " ";
					dif--;
				}
				else
					cout << nn << " ";
			}
		}
	}



}
void solve() {

}

int main() {
	fastio;
	input();
	solve();
}




