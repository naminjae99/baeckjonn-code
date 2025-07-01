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


int par[1000001];


int find(int x) {
	if (par[x] < 0)
		return x;
	return par[x] = find(par[x]);
}
bool uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return 0;
	if (par[a] > par[b])
		swap(a, b);
	par[a] += par[b];
	par[b] = a;
	return 1;
}

int n, m, q;
vector<pair<int, int>> con;
bool vis[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m >> q;

	con.push_back({ -1,-1 });
	memset(par, -1, sizeof(par));
	int x, y;
	for (int i = 1; i <= m; i++) {
		cin >> x >> y;
		con.push_back({ x,y });
	}

	deque <int> qq;
	while (q--) {
		cin >> x;
		qq.push_front(x);
		vis[x] = 1;
	}

	for (int i = 1; i <= m; i++) {
		if (vis[i] == 1)
			continue;
		uni(con[i].first, con[i].second);
	}

	ll total = 0;

	while (!qq.empty()) {
		x = con[qq.front()].first;
		y = con[qq.front()].second;
		qq.pop_front();

		//거꾸로 x,y랑연결해주기
		int nowx = find(x);
		int nowy = find(y);

		//둘다 자기가 루트노드일때
		if (par[x]==-1&&par[y]==-1) {
			//cout << "0: 1증가\n";
			uni(x, y);
			total++;
		}
		//제거했을떄 자기만 뗴어질경우
		else if (par[x] == -1 && par[y] < -1) {
			//cout << "1: " << par[nowy]<<"\n";
			total -= par[nowy];
			uni(x, y);
		}
		else if (par[x] < -1 && par[y] == -1) {
			//cout << "1: " << par[nowx] << "\n";
			total -= par[nowx];
			uni(x, y);
		}
		//둘다 루트노드가 아니고 서로 다른부모를 가진경우
		else if (nowx != nowy) {
			//cout << "2: " << par[nowx]*par[nowy] << "\n";
			total += (par[nowx]*par[nowy]);
			uni(x, y);
		}
		
	
	}
	cout << total;
}