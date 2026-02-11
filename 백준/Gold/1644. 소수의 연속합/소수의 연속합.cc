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


int dx[4] = { 1,0,0,-1 };
int dy[4] = { 0,1,-1,0 };

int n, m, ret, t, k;

int arr[4000005];

void input() {
	cin >> n;
	if (n <= 1){
		cout << 0;
	return;
}
	memset(arr, 1, sizeof(arr));
	arr[0] = arr[1] = 0;

	for (int i = 2; i*i <= n; i++) {
		if (arr[i] == 0)
			continue;
		for (int j = i*i; j <= n; j+=i) 
				arr[j] = 0;
		
	}
	vector<int> v;
	for (int i = 2; i <= n; i++) {
		if (arr[i])
			v.push_back(i);
	}

	m = v.size();

	int l, r;
	l =0;
	r = 0;

	int sum = 0;

	while (1) {

		if (sum >= n) {
			if (sum == n)
				ret++;
			sum -= v[l++];
		}
		else {
			if (r == m)
				break;
			sum += v[r++];
		}

	}
	cout << ret;
}



int main() {
	fastio
		input();

}