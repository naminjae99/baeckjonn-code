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
int arr[605];

void input() {
	cin >> n;
	ret = 1e9;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);


	for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
        int a = arr[i] + arr[j];
        int le = 0, ri = n - 1;
        while (le < ri) {
            if (le == i || le == j) { le++; continue; }
            if (ri == i || ri == j) { ri--; continue; }

            int b = arr[le] + arr[ri];
            ret = min(ret, abs(a - b));

            if (a < b) ri--;
            else le++;

            if (ret == 0) break;
        }
    }
}

	cout << ret;
}
void solve() {



}

int main() {
	fastio;
	input();
	solve();
}




