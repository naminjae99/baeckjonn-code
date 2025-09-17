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
int dx[9] = { 0,-1,-1,0,1,1,1,0,-1 };
int dy[9] = { 0,0,-1,-1,-1,0,1,1,1 };

int n, t, ret, h, k, m,w;

struct Node {
	int id, cost, in;
	bool operator<(const Node& o)const {
		return in < o.in;
	}
};

queue<Node> wait;
vector<Node> add;
int re[200005];

void input() {
	cin >> n >> t >> w;
	for (int i = 0; i < n; i++) {
		int id, cost;
		cin >> id >> cost;
		wait.push({ id,cost });
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int id, cost, x;
		cin >> id >> cost >> x;
		add.push_back({ id,cost,x });
	}
	sort(add.begin(), add.end());
}
void solve() {
	int idx = 0;

	while (!wait.empty()) {
		int id = wait.front().id;
		int cost = wait.front().cost;
		wait.pop();
		if (cost <= t) {
			for (int i = ret; i <= min(w-1,ret + cost); i++) 
				re[i] = id;

			ret += cost;
			while (idx<m&&add[idx].in <= ret) {
				wait.push(add[idx++]);
			}

		}
		else {
			for (int i = ret; i <= min(ret+t,w-1); i++) 
				re[i] = id;
			
			ret += t;
			cost -= t;
			while (idx < m&&add[idx].in <= ret) {
				wait.push(add[idx++]);
			}

			wait.push({ id,cost });
		}
		if (ret > w)
			break;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	input();
	solve();

	for (int i = 0; i < w; i++)
		cout << re[i] << "\n";
}
