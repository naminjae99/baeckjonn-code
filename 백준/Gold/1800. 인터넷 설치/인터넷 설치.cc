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
	int now, pre, cnt;
};

bool cal(int x) {
	queue<f> q;
	q.push({ 1, 0, 0 });

	bool visited[1005][1005] = { 0 };  // 방문 체크
	visited[1][0] = true;

	while (!q.empty()) {
		int now = q.front().now;
		int cnt = q.front().cnt;
		q.pop();

		if (now == n)
			return true;

		for (auto& c : ed[now]) {
			int cost = c.first;
			int next = c.second;
			int nextCnt = cnt;

			if (cost > x) nextCnt++;  // 비싼 간선이면 카운트 증가

			if (nextCnt > k) continue;

			if (!visited[next][nextCnt]) {
				visited[next][nextCnt] = true;
				q.push({ next, 0, nextCnt });
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
			//cout << st << ", " << en << "\n";
		//	cout << mid << "초과하는 노드 k개만 이용하기 성공 \n";
			re = mid;
			en = mid-1;
		}
		else {
		//	cout << st << ", " << en << "\n";
		//	cout << mid << "초과하는 노드 k개만 이용하기 실패 \n";
			st = mid+1;
		}
	}
	
	cout << re;
}
