
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
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;

struct Node {
	int  t, dt;
};
bool cmp(Node a, Node b) {
	if (a.dt != b.dt)
		return a.dt < b.dt;
	return a.t < b.t;
}

int hs;
Node heap[100005];
void push(Node x) {
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
Node pop() {
	Node re = heap[0];
	int i = 0;
	heap[i] = heap[--hs];
	while (1) {
		int le = i * 2 + 1;
		int ri = i * 2 + 2;
		int pr = i;
		if (le < hs && cmp(heap[le], heap[pr]))
			pr = le;
		if (ri < hs && cmp(heap[ri], heap[pr]))
			pr = ri;
		if (pr == i)
			break;
		swap(heap[pr], heap[i]);
		i = pr;
	}
	return re;
}



int now = 0;
Node cur;

int idx = 0;
int total;

int solution(vector<vector<int>> jobs) {
	total = jobs.size();
	int sum = 0;

	sort(jobs.begin(), jobs.end());


	while (1) {
		if (idx >= total &&hs==0)
			break;

		// 현재 시간 이하의 작업 추가
		while (idx < total && jobs[idx][0] <= now) {
			push({jobs[idx][0], jobs[idx][1]});
			idx++;
		}

		if (hs > 0) {
			cur = pop();
			now += cur.dt;
			sum+= now - cur.t;
		}
		else {
			now = jobs[idx][0];
		}
	}

	return sum / total;
}