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


int n;
vector<int> v[200005];
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);

	cin >> n;
	
	for (int i =1; i <=n; i++) {
		int a;
		int b;
		cin >> a >> b;
		v[a].push_back(b);
		
	}
	priority_queue<int>q;
	int sum = 0;
	for (int i = n; i >= 1; i--) {
		for (auto c : v[i])
			q.push(c);
		if (!q.empty()) {
			sum += q.top();
			q.pop();
		}
	}
	cout << sum;
	
}
