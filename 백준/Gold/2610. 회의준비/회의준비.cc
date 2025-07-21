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
#include<array>
using namespace std;
using ll = long long;


int n, m, k, t;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


struct f {
	int x, y, cost;
	bool operator<(const f& o)const {
		return cost > o.cost;
	}
};

int par[105];
set<int> ch[105];
int find(int x) {
	if (par[x] == x)
		return x;
	return par[x] = find(par[x]);
}
int arr[105][105];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		ch[i].insert(i);
		fill(arr[i], arr[i] + n + 1, 1e9);
		arr[i][i] = 0;
	}


	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = 1;
		arr[b][a] = 1;

		a = find(a);
		b = find(b);
		if (a == b)
			continue;
		if (a > b)
			swap(a, b);

		for (auto c : ch[b])
			ch[a].insert(c);
		//	cout << b << "를 " << a << "로 이동\n";
		ch[b].clear();
		par[b] = a;
	}


	for (int k = 1; k <= n; k++) {
		for (int a = 1; a <= n; a++) {
			for (int b = 1; b <= n; b++) {
				if (arr[a][b] > arr[a][k] + arr[k][b])
					arr[a][b] = arr[a][k] + arr[k][b];
			}
		}
	}




	int cnt = 0;
	vector<int> re;
	for (int i = 1; i <= n; i++) {
		if (par[i] == i) {
			cnt++;

			int da = -1;
			int mn = 1e9;
			for (auto c : ch[i]) {
				int tmp = 0;
				for (auto cc : ch[i]) {
					tmp = max(tmp, arr[c][cc]);
				}
				if (mn > tmp) {
					mn = tmp;
					da = c;
				}
			}
			re.push_back(da);
		}
	}
	sort(re.begin(), re.end());
	cout << cnt << "\n";
	for (auto c : re)
		cout << c << "\n";
}
