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

int n;
int arr[105];
int vis[105];
int pv;
set<int> s;
void input() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];


	for (int i = 1; i <= n; i++) {
		if (s.find(i) != s.end())
			continue;
		++pv;
	
		queue<int> q;
		vis[i] = pv;
		q.push(i);

		set<int> tmp;


		bool flag = 0;

		while (!q.empty()) {
			int cur = q.front();
			q.pop();

			tmp.insert(cur);

			int nxt = arr[cur];
			if (vis[nxt]==pv) {
				if (nxt == i)
					flag = 1;
				break;
			}
			else {
				q.push(nxt);
				vis[nxt] = pv;
			}
		}
		if (flag) {
			for (auto c : tmp)
				s.insert(c);
		}
	}

	cout << s.size() << "\n";
	for (auto c : s) {
		cout << c << "\n";
	}
}
void solve() {

}
int main() {
	fastio
		input();
	solve();
}