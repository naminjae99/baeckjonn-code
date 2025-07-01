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



ll f[100005];
ll s[100005];

bool vis[100005];
struct  info{
	ll f, s;
	int idx;
	bool operator<(const info& o) {
		if (s == o.s)
			return o.f<f;
		return s < o.s;
	}
};
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	ll n, m;
	cin >> n >> m;

	ll a, b;
	vector<info> v;
	

	for (int i = 1; i <= n; i++) {
		cin >> a >> b;
		f[i] = a;
		s[i] = b;
	
		v.push_back({ a,b,i });
		
	}

	sort(v.begin(), v.end());

	ll sum, spicy; 
	int st, en,idx;
	ll left, right;

	ll mn = 1e18;

	for (auto c : v) {
		if (vis[c.idx])
			continue;

		sum = c.f;
		spicy = c.s;
		idx = c.idx;
		vis[idx] = 1;


		st=idx-1;
		en=idx+1;

		//cout << sum << ", " << spicy << ", " << idx << "\n";
		while (sum<m) {
			bool f1 = 0;
			bool f2=0;
			if (st >= 1 && vis[st] == 0)
				f1 = 1;
			if (en <= n && vis[en] == 0)
				f2 = 1;

			if (f1&&f2) {
				if (s[st] < s[en]) {
					sum += f[st];
					spicy=max(spicy, s[st]);
					st--;
				}
				else {
					sum += f[en];
					spicy = max(spicy, s[en]);
					en++;
				}
			}
			else if (f1 == 0 && f2) {
				sum += f[en];
				spicy = max(spicy, s[en]);
				en++;
			}
			else if (f1&&f2 == 0) {
				sum += f[st];
				spicy = max(spicy, s[st]);
				st--;
			}
			else if (!f1 && !f2)
				break;
		}
		//cout << spicy << "\n\n";
		if (sum >= m) {
			mn = min(mn, spicy);
			//cout << spicy;
			//break;
		}
	
	}
	
	cout << mn;
	
}