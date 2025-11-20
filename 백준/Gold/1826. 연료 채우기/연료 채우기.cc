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

int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int n, m, ret, t, Q, L,k;

struct f {
	int loc, gas;
};
bool cmp(f a, f b) {
	if (a.gas == b.gas)
		return a.loc < b.loc;
	return a.gas > b.gas;
}
int hs;
f heap[1000005];

void push(f x) {
	int i = hs++;
	while (i) {
		int par = (i - 1) / 2;
		if (!cmp(x,heap[par]))
			break;
		heap[i] = heap[par];
		i = par;
	}
	heap[i] = x;
}
f pop() {
	f re = heap[0];
	int i = 0;
	heap[i] = heap[--hs];
	while (1) {
		int le = i * 2 + 1;
		int ri = i * 2 + 2;
		int pr = i;
		if (le < hs&&cmp(heap[le], heap[pr]))
			pr = le;
		if (ri < hs&&cmp(heap[ri], heap[pr]))
			pr = ri;
		if (pr == i)
			break;
		swap(heap[pr], heap[i]);
		i = pr;
	}
	return re;
}
void input() {
	cin >> n;
	for (int i = 0; i < n;i++) {
		int x, y;
		cin >> x >> y;
		push({ x, y });
	}
	cin >> m >> k;


	while (k<m) {
		bool flag = 0;
		vector<f> tmp;
		while (hs) {
			f now = pop();
			//도달 못하는거
			if (now.loc > k) 
				tmp.push_back(now);
			else {
				n--;
				ret++;
				k += now.gas;
				flag = 1;
				break;
			}
		}

		if (!flag) {
			ret = -1;
			break;
		}
		for (auto c : tmp)
			push(c);


	}
	cout << ret;
}
void solve() {


}

int main() {
	fastio;
	input();
	solve();
}









