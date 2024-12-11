#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<list>
#include<stack>
#include<set>
#include <cmath> 
using namespace std;

int n, m, re;
vector<int> truth;
vector<int> p2h[51];
int par[51];

int find(int x) {
	if (par[x] == x)
		return x;
	return par[x] = find(par[x]);
}
void uni(int x, int y) {
	x = find(x), y = find(y);
	if (x != y)
		par[y] = x;
}
int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		par[i] = i;

	int t_n;
	cin >> t_n;


	while (t_n--) {
		int x;
		cin >> x;
		truth.push_back(x);
	}

	for (int i = 0; i < m; i++) {
		int p_n;
		cin >> p_n;
		for (int j = 0; j < p_n; j++) {
			int x;
			cin >> x;
			p2h[i].push_back(x);
		}

		if (p_n > 1) {
			for (int j = 1; j < p_n; j++)
				uni(p2h[i][0], p2h[i][j]);
		}
	}

	if (!truth.empty()) {
		for (int i = 1; i < truth.size(); i++) {
			uni(truth[0], truth[i]);
		}
	}




	for (int i = 0; i < m; i++) {
		int flag = 0;
		for (int person : p2h[i]) {
			if (!truth.empty() && find(truth[0]) == find(person)) {
				flag = 1;
				break;
			}
		}
		if (!flag)
			re++;
	}

	cout << re;
}