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


int n, m;

ll arr[1000005];
ll st, en;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >>m;
	for (int i = 0; i < n; i++) {
		ll x;
		cin >> x;
		en += x;
		arr[i] = x;
	}
	
	ll mid = 0;
	ll re;
	while (st <= en) {
		mid = (st + en)/2;
		ll sum = 0;
		ll tmp = 0;
		bool flag = 0;
		for (int i = 0; i < n; i++) {
			if(sum + arr[i] <= mid) {
				sum += arr[i];
			}
			else {
				tmp++;
				sum = arr[i];
			}
			if (sum > mid) {
				flag = 1;
				break;
			}
		}
		if (sum <= mid)
			tmp++;

		if(tmp>m)
			flag = 1;

		
		if (flag == 1) {
			st=mid+1;
			
		}
		else {
			re = mid;
			en = mid - 1;
		}

		
	}
	cout << re;
}
