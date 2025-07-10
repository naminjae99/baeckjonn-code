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



set < pair<int, int>> s;
ll sum;
int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);
	cin >> n;

	int x;
	cin >> x;
	s.insert({ x,1 });
	sum = 1;

	for(int i=1;i<n;i++) {
		cin >> x;
		auto it = s.lower_bound({ x,0 });
		//it이 젤큰경우
		if (it == s.end()) {
			sum += prev(it)->second + 1;
			s.insert({ x,prev(it)->second + 1 });
		}
		else {
			if (it == s.begin()) {
				sum+=s.begin()->second + 1;
				s.insert({ x,s.begin()->second + 1 });
			}
			else {
				auto pre = prev(it);
				sum += max(pre->second, it->second) + 1;
				s.insert({ x,max(pre->second,it->second) + 1 });
				
			}
		}
	}
	cout << sum;
}
