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
#include<map>
#include<iomanip>
#include<cfloat>
using namespace std;
using ll = long long;

vector<int> ed[30005];
int n, m;
int level[30005];
vector<int> tra;
int parent[30005];
int root_dis[30005];
void dfs(int x, int par,int dis) {
	level[x] = level[par]+1;
	parent[x] = par;
	root_dis[x] = dis;
	for (auto c : ed[x]) {
		if (c != par)
			dfs(c, x, dis + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		ed[a].push_back(b);
		ed[b].push_back(a);
	}

	dfs(1,0,0);

	cin >> m;
	
	
	for(int i=0;i<m;i++) {
		int x;
		cin >> x;
		tra.push_back(x);
	}

	int sum = 0;
	for (int i = 0; i < m - 1; i++) {
		int fr = tra[i];
		int to = tra[i + 1];

		if (level[fr] < level[to])
			swap(fr, to);

		int a = fr;
		int b = to;
	//	cout << a << ", " << b << "\n";

		while (level[a] != level[b]) {
			a = parent[a];
		}

		int lca = -1;
		if (a == b) {
			lca = b;
		}
		else {
			while (a != b) {
				a = parent[a];
				b = parent[b];
			}
			lca = b;
		}

	//	cout << fr << ", " << to << "의 lca: " << lca << "\n";
		sum+= root_dis[fr] + root_dis[to] - 2 * root_dis[lca];


		
	}
	cout << sum;
}
