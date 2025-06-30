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
using namespace std;
using ll = long long;


int par[1001];
int find(int x) {
	if (par[x] == x)
		return x;
	return par[x] = find(par[x]);
}
bool uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return 0;
	return 1;
}

vector<pair<int,int>> e[1001];
int p, w;

int st, en;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> p >> w;
	for (int i = 0; i < p; i++){
		par[i] = i;
	}
	cin >> st >> en;


	while (w--) {
		int a, b, c;
		cin >> a >> b >> c;
		e[a].push_back({ c,b });
		e[b].push_back({ c,a });
	}
	for (int i = 0; i < p; i++) {
		sort(e[i].begin(), e[i].end());
		reverse(e[i].begin(), e[i].end());
	}

	int d[1001]={0,};
	priority_queue<pair<int, int>, vector<pair<int, int>>>q;
	q.push({ 987654321,st });
	d[st] = 1;


	while (!q.empty()) {
		int cost = q.top().first;
		int now = q.top().second;
		q.pop();
		d[now] = 1;

		if (now == en) {
			cout << cost;
			break;
		}
		for (auto c : e[now]) {
			if (d[c.second]==0) {
				q.push({ min(cost,c.first),c.second });
				
			}
		
			
		}
	}

}