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

int arr[51];
int ch[51];
unordered_map<int, bool>mp;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;

	int x;
	int root;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == -1) {
			root = i;
			arr[i] = x;
		}
		else {
			arr[i] = x;
			ch[x]++;
		}
	}

	cin >> x;
	ch[arr[x]]--;

	int re = 0;
	for (int i = 0; i < n; i++) {
		//	cout << i << " , " << ch[i] << "\n";

		if (ch[i])
			continue;
		if (i == x && i == root)
			break;
		if (i == x)
			continue;
		int now = i;
		bool flag = 0;

		while (1) {
			//	cout << "now: " << now << ", " << arr[now] << "\n";
			if (now == x) {
				flag = 1;
				break;
			}

			now = arr[now];
			if (now == -1)
				break;
		}
		if (flag == 0)
			re++;
		//	cout << re << "\n\n";
	}
	cout << re;
	return 0;

}