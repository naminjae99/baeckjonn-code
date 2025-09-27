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

int dx[4] = { 0,1,0,-1 };
int dy[4] = {  1,0,-1,0};

int n, m;

struct Node {
	int num, t, dt;
};
bool cmp(Node a, Node b) {
	if (a.dt != b.dt)
		return a.dt < b.dt;
	if (a.t != b.t)
		return a.t < b.t;
	return a.num < b.num;
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

vector<Node> v;
bool cmp2(Node a, Node b) {
		return a.t < b.t;
}
int now = 0;
Node cur;
int en[505];
int idx = 0;
int total;
int solution(vector<vector<int>> jobs) {
	total = jobs.size();
	for (int i = 0; i < total;i++)
		v.push_back({ i,jobs[i][0],jobs[i][1] });
	sort(v.begin(), v.end(), cmp2);

	while (idx < total || hs > 0) {
		while (idx < total && v[idx].t <= now) 
			push(v[idx++]);
		

		//대기큐가 있으면 하나뽑고 시간업데이트
		if (hs) {
			cur = pop();
			//now마치는 시간으로 변경
			now += cur.dt;
			en[cur.num] = now - cur.t;
		}
		//시간증가
		else {
			now++;
		}
	}

	int answer = 0;
	for (int i = 0; i < total; i++)
		answer += en[i];

	return answer/total;
}
