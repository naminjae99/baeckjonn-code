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


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, ret, k;

vector<pair<int, int>> v;
ll penwick[1005];

void upd(int i) {
	while (i <= n) {
		penwick[i]++;
		i += i & -i;
	}
}
ll sum(int i) {
	ll re = 0;
	while (i > 0) {
		re += penwick[i];
		i -= i & -i;
	}
	return re;
}

void input() {
	int t;
	cin >> t;

	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m >> k;
		ll re = 0;
    v.clear();
		for (int i = 0; i < k; i++) {
			int x, y;
			cin >> x >> y;
			v.push_back({ y,x });
		}
		sort(v.begin(),v.end());

		fill(penwick, penwick + 1 + n, 0);
	//	memset(penwick, 0, sizeof(int)*(n+1));

		for (auto c:v) {

			//arr[i] 보다 큰거 갯수
			re += sum(n) - sum(c.second);
			upd(c.second);
		}

		cout << "Test case " << tc << ": " << re << "\n";
	}
}
int main() {
	fastio
		input();
}
