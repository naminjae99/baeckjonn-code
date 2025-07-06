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
using f = float;

int t, n, m;
f d[111];
f arr[111][111];
pair<f, f>dapo[111];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	cin >> dapo[0].first >> dapo[0].second;

	f x, y;
	cin >> x >> y;
	
	cin >> n;
	
	if (n > 0) {
		for (int i = 1; i <= n; i++)
			cin >> dapo[i].first >> dapo[i].second;
	}
	dapo[n + 1].first = x;
	dapo[n + 1].second = y;

	for (int i = 0; i < n+2; i++) {
		for (int j = i+1; j < n+2; j++) {
			f a, b, c, d;
			a = dapo[i].first, b = dapo[i].second;
			c = dapo[j].first, d = dapo[j].second;
			f dis = (c - a)*(c - a) + (d - b)*(d - b);
			dis = sqrt(dis);

			if (i == 0) {
				arr[i][j] = dis/5;
			//	cout << i<<"에서"<<j<<"로 갈떄"<<dis/5 << "\n";

			}
			else {
				f tmp;
				if (dis >= 50)
					tmp = (dis - 50) / 5 + 2;
				else
					tmp = (50 - dis) / 5 + 2;
				arr[i][j] = arr[j][i] = min(tmp,dis/5);
				
				
				
			}
		
		}
	}
	//cout << "\n\n\n";
	fill(d, d + n+5, 1e9);

	priority_queue<pair<f,int>,vector<pair<f, int>> >q;
	q.push({ 0,0 });
	d[0] = 0;

	while (!q.empty()) {
		int now = q.top().second;
		f cost = -q.top().first;
		q.pop();

		
		if (d[now] != cost)
			continue;

	//	cout << now << ", " << cost << "사용\n";

		if (now == n + 1)
			break;
		for (int i = 0; i < n + 2; i++) {
			if (i == now)
				continue;
			if (d[i] > cost + arr[now][i]) {
				d[i] = cost + arr[now][i];
				q.push({-d[i],i });
			//	cout << i << " , " << d[i] << "추가\n";
			}
		}
		//cout << "\n\n\n";
	}
	cout << d[n + 1];
}
