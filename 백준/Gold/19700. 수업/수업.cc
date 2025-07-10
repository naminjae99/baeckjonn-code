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
using namespace std;
using ll = long long;


int n,m,k;


vector<pair<int, int>> v;
bool vis[500005];

int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	
	cin >> n ;
	for (int i = 0; i < n; i++) {
		int h, mn;
		cin >> h >> mn;
		v.push_back({ h,mn });
	}
	sort(v.rbegin(), v.rend());
	int cnt = 0;

	
	multiset<int> tmp;
	
	for (int i = 0; i < v.size();i++) {
		int height = v[i].first;
		int k = v[i].second;
		
		//cout << height <<","<< k << "\n";
		auto it = tmp.upper_bound(-k);
		if (it == tmp.end()) {
			tmp.insert(-1);
			//cout << "1개 추가\n";
		}
		else {
			int si = *it;
			tmp.erase(it);
			tmp.insert(si - 1);
		//	cout << "si삭제후 si+1추가\n";
		}
	}
	cout << tmp.size();
}
