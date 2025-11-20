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
	bool operator<(const f& o)const {
		return loc < o.loc;
	}
};
bool cmp(f a, f b) {
	if (a.gas == b.gas)
		return a.loc < b.loc;
	return a.gas > b.gas;
}
int hs;
int heap[10005];

void push(int x) {
	int i = hs++;
	while (i) {
		int par = (i - 1) / 2;
		if (heap[par]>=x)
			break;
		heap[i] = heap[par];
		i = par;
	}
	heap[i] = x;
}
int pop() {
	int re = heap[0];
	int i = 0;
	heap[i] = heap[--hs];
	while (1) {
		int le = i * 2 + 1;
		int ri = i * 2 + 2;
		int pr = i;
		if (le < hs&&(heap[le]>heap[pr]))
			pr = le;
		if (ri < hs&&(heap[ri]> heap[pr]))
			pr = ri;
		if (pr == i)
			break;
		swap(heap[pr], heap[i]);
		i = pr;
	}
	return re;
}

vector<f> v;
void input() {
	cin >> n;
	for (int i = 0; i < n;i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end());
	cin >> m >> k;

	int st = 0;

	while (k<m) {
	

		//이동가능한 애들 큐에 넣기
		for (int i = st; i < n; i++) {
			if (v[i].loc <= k) {
				push(v[i].gas);
			}
			else {
				st = i;
				break;
			}
		}

		if (hs == 0) {
			ret = -1;
			break;
		}
		k+= pop();
		ret++;
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









