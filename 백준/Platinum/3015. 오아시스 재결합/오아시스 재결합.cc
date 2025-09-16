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
#include<limits.h>
#include<cfloat>
using namespace std;
using ll = long long;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int n, t, m;

int arr[500005];
ll ret;
//두점 사이에 두점 보다 큰값이 없는 경우 수

void input() {
	cin >> n;

	stack<pair<int,int>> s;
	int now;
	for (int i = 0; i < n; i++) {
		cin >> now;
		int cnt = 1;
		while (!s.empty() && s.top().first <= now) {
			ret += (ll)s.top().second;
			if (s.top().first == now)
				cnt += s.top().second;
			s.pop();
		}
		if (!s.empty())
			ret++;
		s.push({ now,cnt });
	}


	cout << ret;
}

void solve() {
	

}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	input();
	solve();

	
}
