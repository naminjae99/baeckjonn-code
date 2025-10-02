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
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;

int dx[8] = { -1,-1,0,1,1,1,0,-1 };
int dy[8] = { 0,-1,-1,-1,0,1,1,1 };

int n, m, ret, k, t, h, w;
struct f {
	int idx, work, g;
	bool operator<(const f& o)const {
		if (work != o.work)
			return work < o.work;
		if (g != o.g)
			return g < o.g;
		int x, y;
		x = idx % m;
		if (x == 0)
			x = m;
		y = o.idx % m;
		if (y == 0)
			y = m;
		return x > y;
	}
};
f info[100005];

priority_queue<f> q;

void input() {
	cin >> n >> m >> k;
	for (int i = 1; i <=n; i++) {
		int x, y;
		cin >> x >> y;
		info[i] = { i,x,y };
	}



	for (int i = 1; i <=m; i++) {
		if (i > n)
			break;
		q.push(info[i]);
	}

	while (!q.empty()) {
		f cur = q.top();
		q.pop();
	
//		cout << cur.idx << "나옴\n";

		if (cur.idx == k + 1) {
			break;
		}

		ret++;
		int idx = cur.idx;
		if (idx + m > n)
			continue;
		q.push(info[idx + m]);
	}
	cout << ret;

}
int main() {
	fastio;
	input();
}