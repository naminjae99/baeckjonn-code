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


int t, n, m;

vector<pair<ll, int>> ed[50005];
ll d[50005][2];
int f, s;

struct info {
	ll cost;
	int now, cnt;
	bool operator<(const info& o)const {
		return cost > o.cost;

	}
};
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL);
	cin >> n >> m >> f >> s >> t;

	while (m--) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		ed[a].push_back({ c,b });
		ed[b].push_back({ c,a });
	}
	while (f--) {
		int a, b;
		cin >> a >> b;
		ed[a].push_back({ (ll)0,b });
	}

	for (int i = 0; i < n; i++)
		d[i][0] = d[i][1] = 1e18;
	priority_queue<info> q;
	q.push({ 0,s,0 });
	d[s][1] = d[s][0] = 0;

	while (!q.empty()) {
		int now = q.top().now;
		ll cost = q.top().cost;
		int cnt = q.top().cnt;
		q.pop();

		//cout << now << ", " << cost << ", " << cnt << "확인\n";
		if (d[now][cnt]!=cost) {
			//	cout << "Pass\n";
			continue;
		}
		if (now == t) {
			cout << d[now][cnt];
			break;
		}

		for (auto c : ed[now]) {
			//cout << c.second << ", " << c.first << "확인중...\n";
			//cout << d[c.second][cnt] << " , " << c.first << ", " << cost << "\n\n";
			if (c.first == 0&&cnt==0) {
				if (d[c.second][1] > cost) {
					d[c.second][1] = cost;
					q.push({ d[c.second][1],c.second,1 });
					//	cout << c.second << ", " << d[c.second][1] << ", " << cnt+1 << "추가\n";
				}
			}
			else if(c.first!=0){

				if (d[c.second][cnt] > c.first + cost) {
					d[c.second][cnt] = cost + c.first;
					q.push({ d[c.second][cnt],c.second,cnt });
					//cout << c.second << ", " << d[c.second][cnt] << ", " << cnt << "추가\n";

				}
			}
		}
		//cout << "\n\n";
	}

}
