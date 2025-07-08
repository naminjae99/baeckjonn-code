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
vector<pair<int, int>> ed[1005];


// n번노드가 몇번쨰 방문중인지-idx반환


vector<priority_queue<int>> d(1005);

struct f {
	int cost, now;
	bool operator<(const f& o)const {
		
		return cost > o.cost;
	}
};


int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);

	cin >> n>>m>>k;
	while (m--) {
		int a, b, c;
		cin >> a >> b >> c;
		ed[a].push_back({ c,b });
	}
	
	

	priority_queue<f>q;
	q.push({ 0,1 });
	//1을 한번방문했고 방문했을떄 거리가 0
	d[1].push(0);


	while (!q.empty()) {
		int cost = q.top().cost;
		int now = q.top().now;
		q.pop();

		//cout << cost << " 비용의, " << now << " 확인\n";

		for (auto c : ed[now]) {
			int ncost = c.first + cost;
			int nnow = c.second;

			if (d[nnow].size() < k) {
				d[nnow].push(ncost);
				q.push({ ncost,nnow });
			}
			//젤큰 경로
			else if (d[nnow].top() > ncost) {
				d[nnow].pop();
				d[nnow].push(ncost);
				q.push({ ncost,nnow });
			}
		}

	}
	

	for (int i = 1; i <= n; i++) {
		if (d[i].size() != k)
			cout << -1 << "\n";
		else {
			cout << d[i].top() << "\n";
		}
	}

}
