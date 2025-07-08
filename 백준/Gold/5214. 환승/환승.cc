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


int n,m,k;
int vis[101005];
vector<int> ed[101005];

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	
	cin >> n >> k >> m;

	int cnt = 0;

	while (m--) {
		int x;
		cnt++;
		//cnt역이 사실 하이퍼튜브
		for (int i = 0; i < k; i++) {
			cin >> x;
			ed[n+cnt].push_back(x);
			ed[x].push_back(n+cnt);
		}
	}


	vis[1] = 1;
	queue<int>q;
	q.push(1);

	while (!q.empty()) {
		int x = q.front();
		q.pop();

		if (x == n) {
			cout << vis[x];
			return 0;
		}
		for (auto c : ed[x]) {
			if (vis[c] == 0) {
				//하이퍼튜브로 가는거면
				if (c > n)
					vis[c] = vis[x];
				else
					vis[c] = vis[x] + 1;
				q.push(c);
			}
		}
	}
    cout<<-1;
	
}
