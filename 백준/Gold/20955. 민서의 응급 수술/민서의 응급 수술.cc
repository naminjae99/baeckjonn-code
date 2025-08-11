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
#include<iomanip>
#include<unordered_set>

using namespace std;


int par[100005];
int find(int x) {
	if (par[x] < 0)
		return x;
	return par[x] = find(par[x]);
}
int n, m;
int main(){
	ios::sync_with_stdio(0), cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		par[i] = -1;
	int a, b;
	
	int re = 0;
	while (m--) {
		cin >> a >> b;
		a = find(a);
		b = find(b);
		if (a == b) 
			re++;
		else 
			par[a] = b;
		
	}
	for (int i = 1; i <= n; i++) {
		if (find(i) != i)
			continue;
		re++;
	}
	cout << re- 1;

}