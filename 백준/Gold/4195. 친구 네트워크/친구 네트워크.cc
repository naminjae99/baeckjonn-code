#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include<iomanip>
#include<string>
#include<memory.h>
#include<array>
#include<unordered_map>
#include<algorithm>
#include<set>
#include<sstream>
using namespace std;




int p[200002];
int n, m;
int cnt[200002];

int f(int x) {
	if (p[x] < 0)
		return x;
	return p[x] = f(p[x]);
}

int u(int a, int b) {
	a = f(a);
	b = f(b);

	if (a == b)
		return p[a];

	//b랭크가 더높을경우 교환
	if (p[a] > p[b])
		swap(a, b);
	
	p[a] += p[b];

	p[b] = a;
	return p[a];
}

unordered_map<string, int> mp;
int idx;
int main() {
    	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n;

	while (n--) {
		memset(p, -1, sizeof(p));
	
		cin >> m;
		idx = 0;
		mp.clear();

		string s1,s2;
		while (m--){
			cin >> s1 >> s2;
			
			int id1, id2;
			if (mp.find(s1)==mp.end())
				mp[s1] = idx++;
			id1 = mp[s1];

			if (mp.find(s2)==mp.end())
				mp[s2] = idx++;
			id2 = mp[s2];
			

			cout<< -u(id1, id2)<<"\n";
		}
		
		
		
	}
}