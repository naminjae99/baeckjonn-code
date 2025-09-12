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
#include<cfloat>
using namespace std;
using ll = long long;
int dx[5] = {0,-1,1,0,0};
int dy[5] = {0,0,0,1,-1};

int n, m, t, ret, h, k;
int arr[10005];
void input() {
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	int l = 0;
	int r = 0;
	int sum = arr[0];


	while (r<n && l<n) {
		
		if (l > r) {
			r = l;
			sum = arr[r];
		}
		//cout << l << "," << r << ": " << sum << "\n";
		if (sum < m) {
			sum += arr[++r];
		}
		else if (sum == m) {
			ret++;
			sum -= arr[l++];
		}
		else {
			sum -= arr[l++];
		}
	}

}

void move() {


}


void solve() {


	
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	input();
	solve();
	cout << ret;

}
