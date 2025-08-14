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


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	string s,ss;

	//int mx = -1;
	int re1 = 1e9;
	int re2=1e9;

	vector<string> arr(n);
	for(int i=0;i<n;i++) 
		cin >> arr[i];
	

	for (int i = 100; i > 0; i--) {
		unordered_map<string, int>mp;

		for (int j = 0; j < n; j++) {
			if (arr[j].size() < i)
				continue;
			ss=arr[j].substr(0, i);
			if (mp.find(ss) == mp.end())
				mp[ss] = j;
			else {

				if (re1 > mp[ss]) {
					re1 = mp[ss];
					re2 = j;
				}
		


			}

		}
		if (re1 != 1e9) {
			cout << arr[re1] << "\n" << arr[re2];
			return 0;
		}
	}

	
	
	//cout << s1 << "\n"<<s2 << "\n";
}
