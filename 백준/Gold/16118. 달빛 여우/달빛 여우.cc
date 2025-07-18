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

vector<pair<double,int>> ed[4005];
int n, m;

double d[4005];
double dd[2][4005];

struct f {
	int now;
	double dis;
	bool cnt;
	bool operator<(const f& o)const {
		return dis > o.dis;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n >> m;
	while (m--) {
		int a, b;
		double c;
		cin >> a >> b >> c;
		ed[a].push_back({ c,b });
		ed[b].push_back({ c,a });
	}


		fill(d, d + n + 1, DBL_MAX);
		fill(dd[0], dd[0] + n + 1, DBL_MAX);
		fill(dd[1], dd[1] + n + 1, DBL_MAX);
	
	priority_queue<f>q;
	d[1] = 0;
	q.push({ 1,0,0 });
	while (!q.empty()) {
		int now = q.top().now;
		double dis = q.top().dis;
		q.pop();
		if (d[now] != dis)
			continue;
		for (auto c : ed[now]) {
			if (d[c.second] > c.first + dis) {
				d[c.second] = c.first + dis;
				q.push({ c.second,d[c.second],0 });
			}
		}
	}

	
	dd[0][1] = 0;
	q.push({ 1,0,0 });
	while (!q.empty()) {
		int now = q.top().now;
		double dis = q.top().dis;
		bool cnt = q.top().cnt;
		q.pop();
		if (dd[cnt][now] != dis)
			continue;
		for (auto c : ed[now]) {
			//2배로 속력으로
			if (cnt == 0) {
				if (dd[!cnt][c.second] > c.first/2 + dis) {
					dd[!cnt][c.second] = c.first/2 + dis;
					q.push({ c.second,dd[!cnt][c.second],!cnt });
				}
			}
			else {
				if (dd[!cnt][c.second] > c.first * 2 + dis) {
					dd[!cnt][c.second] = c.first * 2 + dis;
					q.push({ c.second,dd[!cnt][c.second],!cnt });
				}
			}
		}
	}
	int count = 0;
	for (int i = 2; i <= n; i++) {
		if (d[i] < min(dd[1][i],dd[0][i])) {
			//cout << i << "번: ";
		//	cout << d[0][i] << ", " << d[1][i] << "\n";
			count++;
		}
	}
	cout << count;
}
