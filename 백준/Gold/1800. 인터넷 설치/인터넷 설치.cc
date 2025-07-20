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


int n, m,k;
vector<pair<int, int>> ed[1005];


struct f {
	int now, cnt;
	bool operator<(const f& o)const {
			return cnt > o.cnt;
	}
};
int d[1005];
bool cal(int x) {
	priority_queue<f> q;
	q.push({ 1, 0 });
	fill(d, d + n + 1, 1e9);
	d[1] = 0;
	
	while (!q.empty()) {
		int now = q.top().now;
		int cnt = q.top().cnt;
		
		q.pop();
		if (d[now] < cnt)
			continue;
		if (now == n)
			return true;

		for (auto& c : ed[now]) {
			if (c.first > x) {
				if (cnt == k)
					continue;
				if (d[c.second] > cnt+1) {
					d[c.second] = cnt+1;
					q.push({ c.second,cnt + 1 });
				}
			}
			else {
				if (d[c.second] >cnt) {
					d[c.second] = cnt;
					q.push({ c.second,cnt });
				}
			}

			
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;

	int en = -1;
	while (m--) {
		int a, b, c;
		
		cin >> a >> b >> c;
		en = max(en, c);
		ed[a].push_back({ c,b });
		ed[b].push_back({ c,a });
	}

	int st = 0;

	int mid;
	int re=-1;
	while (st <=en) {
		mid = (st + en) / 2;
		//미드를 지불하니깐 미드이상인 노드는 k만이용하기
		if (cal(mid)) {
		//	cout << st << ", " << en << "\n";
			//cout << mid << "초과하는 노드 k개만 이용하기 성공 \n";
			re = mid;
			en = mid-1;
		}
		else {
	//		cout << st << ", " << en << "\n";
	//		cout << mid << "초과하는 노드 k개만 이용하기 실패 \n";
			st = mid+1;
		}
	}
	
	cout << re;
}
