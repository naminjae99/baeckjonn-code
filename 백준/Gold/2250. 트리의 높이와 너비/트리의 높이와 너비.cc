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

pair<int,int> ch[10001];
int mx[10001];
int mn[10001];
int loc[10001];
int par[10001];

int count(int node) {
	//cout << node << "실행\n";
	if (node == -1)
		return 0;

	int sum = 1;
	sum += count(ch[node].first);
	sum += count(ch[node].second);
	
	return sum;
}
void f(int node, int st, int en, int h) {
	int left=count(ch[node].first);
	
		;	//st+left== node의 위치
	loc[node] = st + left;
	mn[h] = min(mn[h], st + left);
	mx[h] = max(mx[h], st + left);


	//cout << node << "보다 왼쪽에 있는 갯수 :" << left << " 즉, " << st + left << "에 들어감\n";
	if (ch[node].first!=-1)
		f(ch[node].first, st, st + left - 1, h + 1);
	if (ch[node].second!=-1)
		f(ch[node].second, st + left + 1,en, h + 1);

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	int a, b, c;
	memset(par, -1, sizeof(par));
	memset(mx, 0, sizeof(mx));
	for (int i = 1; i <= n; i++)
		mn[i] = n + 1;

	for (int i = 1; i <= n; i++) {
		cin >> a >> b >> c;

		ch[a].first = (b);
		if(b!=-1)
		par[b] = a;

		ch[a].second = (c);
		if (c != -1) 
			par[c] = a;
		
	}
	int root=0;
	int now = 1;
	while (par[now] != -1) 
		now = par[now];
	
	root = now;
	//cout << root << ": root \n";
	f(root, 1, n, 1);

	int lev = 10001;
	int wid = -1;
	for (int i = 1; i <= 10000; i++) {
	//	cout << i << " 높이: " << mx[i] << ", " << mn[i] << "\n";
		int tmp = mx[i] - mn[i]+1;

		if (tmp == 0)
			break;
		if (wid < tmp) {
			wid = tmp;
			lev = i;
		}
	}
	cout << lev << " " << wid;
}
