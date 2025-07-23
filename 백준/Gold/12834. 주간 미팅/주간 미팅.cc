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
#include<array>
using namespace std;
using ll = long long;


int Q, n, m, k, t;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
struct f {
	int now;
	ll cost;
	bool operator<(const f& o)const {
		return cost > o.cost;
	}
};
ll d[1005];
ll dd[1005];
vector<int> fr;
vector<pair<ll, int>>ed[1005];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m>>k;

	int dst, dst2;
	cin >> dst >> dst2;
	
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		fr.push_back(x);
	}
	while (k--) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		ed[a].push_back({ c,b });
		ed[b].push_back({ c,a });
	}

	fill(d, d + m + 1, 1e18);
	priority_queue<f>q;
	d[dst] = 0;
	q.push({ dst,0 });
	while (!q.empty()) {
		int now = q.top().now;
		ll cost = q.top().cost;
		q.pop();
		if (d[now] != cost)
			continue;
		for (auto c : ed[now]) {
			if (d[c.second] > c.first + cost) {
				d[c.second] = c.first + cost;
				q.push({ c.second,d[c.second] });
			}
		}
	}
	q = {};
	fill(dd, dd + m + 1, 1e18);
	dd[dst2] = 0;
	q.push({ dst2,0 });
	while (!q.empty()) {
		int now = q.top().now;
		ll cost = q.top().cost;
		q.pop();
		if (dd[now] != cost)
			continue;
		for (auto c : ed[now]) {
			if (dd[c.second] > c.first + cost) {
				dd[c.second] = c.first + cost;
				q.push({ c.second,dd[c.second] });
			}
		}
	}
	ll sum = 0;
	for (auto c:fr) {
	
			//cout << i << ": " << d[i] << ", " << dd[i] << "\n";
			if (d[c] == 1e18)
				sum--;
			else
				sum += d[c];

			if (dd[c] == 1e18)
				sum--;
			else
				sum += dd[c];
		
			
	}
	cout << sum;
}


