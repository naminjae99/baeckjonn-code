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
#include<cfloat>
using namespace std;
using ll = long long;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int n, t, ret, h, k, m;

struct f {
	int x, y, c;
	bool operator<(const f& o)const {
		return c > o.c;
	}
};
vector<f> ed;

vector<f> q;
int par[5005];

int find(int x) {
	if (par[x] < 0)
		return x;
	return par[x] = find(par[x]);
}
void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	par[a] += par[b];
	par[b] = a;
}
int re[5005];

void input() {
	cin >> n >> m;
	memset(par, -1, sizeof(par));
	for (int i = 0; i < n-1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		ed.push_back({ a,b,c });
	}
	sort(ed.begin(), ed.end());

	for(int i=0;i<m;i++){
		int a, b;
		cin >> a >> b;
		q.push_back({ b,i,a });
	}

	sort(q.begin(), q.end());

	int ii = 0;

	for (auto c : q) {
		int kk = c.c;
		int idx = c.y;
		int st = c.x;

		for (int i = ii; i < n - 1;i++) {
			if (ed[i].c >= kk) 
				uni(ed[i].x, ed[i].y);
			else {
				ii = i;
				break;
			}
		}
	
		re[idx] = -par[find(st)] - 1;


	}
	for (int i = 0; i < m; i++) {
		cout << re[i] << "\n";
	}
}


void solve() {


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	input();
	solve();
	//cout << ret;

}
