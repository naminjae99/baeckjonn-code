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

int n, m,k,re;
int vis[500001][2];

int main() {
	ios::sync_with_stdio(0), cout.tie(0), cin.tie(0);
	cin >> n>>k;
	queue < pair<int, int>>q;
	q.push({n,0});
	vis[n][0] = 1;
	
	while (!q.empty()) {
		int now = q.front().first;
		int t = q.front().second;
		q.pop();
		int mok = k + t * (t + 1) / 2;

		if (mok > 500000) {
			break;
		}
		
		if (vis[mok][t%2]) {
			cout << t;
			return 0;
		}

		if (now > 0) {
			if (vis[now - 1][(t + 1) % 2] == 0) {
				q.push({ now - 1, t + 1 });
				vis[now - 1][(t + 1) % 2] = 1;
			}
		}
		if (now < 500000) {
			if (vis[now + 1][(t + 1) % 2] == 0) {
				q.push({ now + 1, t + 1 });
				vis[now + 1][(t + 1) % 2] = 1;
			}
		}
		if (now <= 250000) {
			if (vis[now*2][(t + 1) % 2] == 0) {
				q.push({ now * 2, t + 1 });
				vis[now * 2][(t + 1) % 2 ]= 1;
			}
		}
			
		

	}
	
		cout << -1;
}