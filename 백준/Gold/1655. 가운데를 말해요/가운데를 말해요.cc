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


int main() {
	ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(0);

	cin >> t;
	priority_queue<int,vector<int>,greater<int>> r;
	priority_queue<int> l;

	vector <int> re;
	int lc = 0;
	int rc = 0;
	int now;

	for(int i=1;i<=t;i++) {
		int x;
		cin >> x;
		if (i == 1) {
			
			now = x;
			re.push_back(x);
			continue;
		}

		if (now <= x) {
		//	cout << x << "오른쪽 \n";
			r.push(x);
			rc++;
		}
		else {
		//	cout << x << "왼쪽 \n";
			l.push(x);
			lc++;
		}
		


		if (i % 2 == 0) {
			if (lc > rc) {
				re.push_back(min(now, l.top()));
			}
			else {
				re.push_back(min(now, r.top()));
			}

			//re.push_back(now);
			
		}
		else {
			if (rc == lc)
				re.push_back(now);
			else if (rc > lc) {
				l.push(now);
				now = r.top();
				r.pop();
				lc++;
				rc--;
				re.push_back(now);
			}
			else {
				r.push(now);
				now = l.top();
				l.pop();
				lc--;
				rc++;
				re.push_back(now);
			}
		//	cout << now << ": now \n";
		}

	}
	for (auto c : re)
		cout << c << "\n";
}
