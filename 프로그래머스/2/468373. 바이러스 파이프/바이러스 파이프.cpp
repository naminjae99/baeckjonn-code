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

int dx[9] = { -1,0,1,0 };
int dy[9] = { 0,1,0,-1 };

int ord[10];
int ret;
int st;
vector<int> ed[105][3];
int vis[105];
int pv;

void dfs(int dep, int n, int k) {
	if (dep == k) {
		set<int> s;
		s.insert(st);


		for (int i = 0; i < k; i++) {

			int p = ord[i];
			++pv;
			queue<int> q;
			cout << "기존: ";
			for (auto c : s) {
				vis[c] = pv;
				q.push(c);
				cout << c << " ";
			}
			cout << "에서 파이프"<<p<<"열기\n";
		

			while (!q.empty()) {
				int x = q.front();
				q.pop();
				s.insert(x);
				for (auto c : ed[x][p]) {
					if (vis[c] == pv)
						continue;
					q.push(c);
					vis[c] = pv;
				}
			}
			
	
		}

		ret = max(ret, (int)s.size());
		return;
	}
	for (int i = 0; i < 3; i++) {
		ord[dep] = i;
		dfs(dep + 1, n, k);
	}
}
int solution(int n, int infection, vector<vector<int>> edges, int k) {
	st = infection;
	for (auto c : edges) {
		int x = c[0];
		int y = c[1];
		int p = c[2]-1;
		ed[x][p].push_back(y);
		ed[y][p].push_back(x);
	}
	
	
	dfs(0,n,k);

	return ret;
}

void input() {
	
}



void run() {


}


int main() {
	fastio
		input();
	run();

}


