#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <string.h>
#include <set>
#include <iomanip>
#include <unordered_set>
#include <map>
#include<cfloat>
using namespace std;
using ll = long long;
struct State {
	int now;
	ll cost;
}heap[100005];
bool cmp(State a, State b) {
	return a.cost < b.cost;
}
int hs;
void push(State x) {
	int i = hs++;
	while (i) {
		int par = (i - 1) / 2;
		if (!cmp(x, heap[par]))
			break;
		heap[i] = heap[par];
		i = par;
	}
	heap[i] = x;
}
State pop() {
	State ret = heap[0];
	int i = 0;
	heap[i] = heap[--hs];
	while (1) {
		int le = i * 2 + 1;
		int ri = i * 2 + 2;
		int pr = i;
		if (le < hs&& cmp(heap[le], heap[pr]))
			pr = le;
		if (ri < hs&& cmp(heap[ri], heap[pr]))
			pr = ri;
		if (pr == i)
			break;
		swap(heap[pr], heap[i]);
		i = pr;
	}
	return ret;
}
int n, m, k, r, F;

vector<pair<int, int>> v;

unordered_map<int,set<int>>mp;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> m;
	int ox, oy;

	int x, y;
	cin >> ox >> oy;

	for (int i = 1; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back({ a - ox,b - oy });
	}

	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		mp[a].insert(b);
	}


	for (auto c : mp) {
		for (auto cc : c.second) {
			x = c.first;
			y = cc;

		//	cout << x << "," << y << "기준으로\n";

			bool flag = 0;

			for (int i = 0; i < m - 1; i++) {
				if (mp.find(x + v[i].first) == mp.end()) {
					flag = 1;
					break;
				}
				if (mp[x + v[i].first].find(y+v[i].second) == mp[x+v[i].first].end()) {
					flag = 1;
					break;
				}
				//cout << x + v[i].first << "," << y + v[i].second << "가 존재\n";
			}
			if (flag == 0) {
				cout << x - ox << " " << y - oy;
				return 0;
			}
		}
	}

}
