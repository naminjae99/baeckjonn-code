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
int arr[200];

void input() {
	cin >> n >> m>>k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + n+1);
	arr[n + 1] = k;

	int le = 1;
	int ri = k;
	int mid, re;

	while (le <= ri) {
		mid = (le + ri) >> 1;

		//간격이 mid이내이게 하기
		int cnt = 0;
		for (int i = 0; i <= n; i++) {
			int len = arr[i + 1] - arr[i];
			if (len > mid) {
			///	cout << "간격이 " << len << "으로 " << mid<<"로 만들려면" << ((len+mid-1) / mid)-1 <<"개필요\n";
				cnt += ((len + mid - 1) / mid) - 1;
			}
		}

	//	cout << mid << "간격이하로 만들떄 필요한 갯수" << cnt << "\n";

		//mid가 너무 작아서 많이 필요함 
		if (cnt > m) {
			le = mid + 1;
		}
		else {
			re = mid;
			ri = mid - 1;
		}

	}
	cout << re;
}
void solve() {



}

int main() {
	fastio;
	input();
	solve();
}




