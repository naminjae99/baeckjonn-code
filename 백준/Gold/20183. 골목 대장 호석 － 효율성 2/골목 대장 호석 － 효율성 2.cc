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
int s,e;
ll k;

struct f {
	ll  cost;
	int now;
	bool operator<(const f& o)const {

			return cost > o.cost;
	

	}
};

vector< pair<ll, int>> ed[100005];
ll d[100005];
bool flag;

bool dik(int x) {
	fill(d, d + n+1, 1e18);
	priority_queue<f>q;
	q.push({ 0,s });
	d[s] = 0;

	while (!q.empty()) {
		int now = q.top().now;
		ll cost = q.top().cost;
	
		q.pop();
		if (d[now] != cost)
			continue;
		if (now == e ) {
			if(cost<=k)
				return 1;
			return 0;
		}
		

		for (auto c : ed[now]) {

			if (c.first<=x&&d[c.second] > c.first + cost) {
				d[c.second] = c.first + cost;
				q.push({d[c.second],c.second });
			}
		}
	}
	return 0;
}

ll le = 1e18;
ll ri;

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL),  cout.tie(0);

	cin >> n>>m>>s>>e>>k;
	while (m--) {
		int a, b;
		ll  c;
		cin >> a >> b >> c;
		ed[a].push_back({ c,b });
		ed[b].push_back({ c,a });
		le = min(le, c);
		ri= max(ri, c);
	}

	ll mid;
	ll re = -1;
	while (le <=ri) {
		mid = (le + ri) / 2;

		//mid비용이하의 간선만 이용했을때 
		//가능하면 ri=mid
		//불가능하면 le=mid+1;
		if (dik(mid)) {
			re = mid;
			ri = mid-1;
		}
		else
			le = mid + 1;
		
	}
	cout << re;
}
