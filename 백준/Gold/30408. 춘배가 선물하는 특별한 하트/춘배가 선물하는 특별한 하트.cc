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
#include<sstream>
#include<numeric>
#include <limits>
using namespace std;
using ll = long long;



int n, m, k;
vector<pair<int, ll>> ed[100005];

int hs;
struct f{
	int now;
	ll cost;
}heap[1000005];
void push(f x) {
	int i = hs++;
	while (i) {
		int par = (i - 1) / 2;
		if (heap[par].cost <= x.cost)
			break;
		heap[i] = heap[par];
		i = par;
	}
	heap[i] = x;
}
f pop() {
	f ret = heap[0];
	int i = 0;
	heap[i] = heap[--hs];
	while (1) {
		int le = i * 2 + 1;
		int ri = i * 2 + 2;
		int pr = i;
		if (le < hs&&heap[le].cost < heap[pr].cost)
			pr = le;
		if (ri < hs&&heap[ri].cost < heap[pr].cost)
			pr = ri;
		if (pr == i)
			break;
		swap(heap[pr], heap[i]);
		i = pr;
	}
	return ret;
}


unordered_set<ll> vis;

int fr, ba;
ll q[100000005];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll nn, mm;
	cin >> nn>>mm;
	
	q[ba++] = nn;
	vis.insert(nn);

	while (fr < ba) {
		ll now = q[fr++];

		if (now == mm) {
			cout << "YES";
			return 0;
		}
		if (now == 1)
			continue;

		if (now % 2 == 1) {
			if (vis.find(now / 2) == vis.end()) {
				q[ba++] = now / 2;
				vis.insert(now / 2);
			}
			if (vis.find(now / 2 + 1) == vis.end()) {
				q[ba++] = now / 2 + 1;
				vis.insert(now / 2+1);
			}
		}
		else {
			if (vis.find(now / 2) == vis.end()) {
				q[ba++] = now / 2;
				vis.insert(now / 2);
			}
		}
	}
	cout << "NO";
}


