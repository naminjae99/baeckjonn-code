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
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int n, m, k, t, Q, ret;
bool outbound(int x, int y) {
	return (x < 0 || x >= n || y < 0 || y >= m);
}


int vis[100005];

void input() {
	cin >> n>>m;
	for (int i = 0; i <= 100000; i++)
		vis[i] = 1e9;
	vis[n] = 0;
	queue<int> q;
	q.push(n);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		if (cur == m) {
			cout << vis[cur];
			break;
		}
		
		if (cur > 0 && vis[cur - 1] == 1e9) {
			vis[cur - 1] = vis[cur] + 1;
			q.push(cur - 1);
		}
		if (cur < 100000 && vis[cur + 1] == 1e9) {
			vis[cur + 1] = vis[cur] + 1;
			q.push(cur + 1);
		}
		if (cur <= 50000 && vis[2 * cur] == 1e9) {
			vis[2 * cur] = vis[cur] + 1;
			q.push(2 * cur);
		}
	}

}
void solve() {

}
int main() {
	fastio
		input();
	solve();
}