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


int par[100005];

int find(int x) {
	if (par[x] == x)
		return x;
	return par[x] = find(par[x]);
}
void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	if (a > b) {
		par[a] = b;
	}
	else
		par[b] = a;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		par[i] = i;
	bool vis[100005] = { 0, };
	int x;
	int cnt = 0;
	while (m--) {
		cin >> x;
	
		
		//x의 시작가능한지점
		int p = find(x);

		if (vis[p] == 0) {
			vis[p] = 1;
			cnt++;
			//cout << p << "에 들어감\n";
		}
		else {
			int pre = p;
			int now = find(p - 1);
			bool flag = 0;

			while (now >0) {
				if (vis[now] == 0) {
					vis[now] = 1;
					flag = 1;
					cnt++;
					break;
				}
				uni(pre, now);
				//cout << pre << ","<< now << "합\n";
				pre = now;
				now = find(now-1);
			}
			if (flag == 0)
				break;
		}
		

		
	}
	
	cout << cnt;

	
	
}