#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
#include<string.h>
#include<set>
using namespace std;
using ll = long long;

int t, m, n;


int p[300005];
int f(int x) {
	if (p[x] ==x)
		return x;
	return p[x] = f(p[x]);
}
bool vis[300005];
void uni(int a, int b) {
	a = f(a);
	b = f(b);
	if (vis[a] == 0) 
		p[b] = a;
	else
		p[a] = b;
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> m;
	int a, b;
	for (int i = 1; i <= m; i++)
		p[i] = i;

	for (int i = 1; i <= n; i++) {
		cin >> a>>b;
		a = f(a);
		b = f(b);
		if (vis[a] == 0) {
			vis[a] = 1;
			uni(a, b);
			cout << "LADICA\n";
		}
		else if (vis[b] == 0) {
			vis[b] = 1;
			uni(a, b);
			cout << "LADICA\n";
		}
		else {

			uni(a, b);
			cout << "SMECE\n";
		}	
	
	}

}