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
#include<sstream>
#include<iomanip>
using namespace std;
using ll = long long;
int dx[4] = { -1, 1, 0, 0 }; // up, down, right, left
int dy[4] = { 0, 0, 1, -1 };

int n, m,t;
int arr[200005];
int arr2[200005];

int cal(int lim) {
	int st = 0;
	int cnt = 0;

	for (int i = 0; i < m; i++) {
		int s = arr2[i];
		bool flag = 0;

		//lim보다 작거나 같은 수로 구성된 연속된 s개를 찾아야함
		for (int j = st; j < n; j++) {
			
			if (arr[j] <= lim) {
				cnt++;
			}
			else {
				cnt = 0;
				continue;
			}

			if (s == cnt) {
				st = j+1;
				cnt = 0;
				flag = 1;
				break;
			}
		}

		if (flag==0) 
			return 0;
	}
	return 1;

}
void input() {
	cin >> t;
	for (int tc = 1; tc <= t; tc++) {
		cin >> n >> m;
		
		int st = 1;
		int en = 1;

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
			en = max(en, arr[i]);
		}
		for (int i = 0; i < m; i++)
			cin >> arr2[i];
		int mid;
		int re=en;

		while (st <= en) {
			mid = (st + en) / 2;
			int x=cal(mid);

			if (x) {
				re = mid;
				en = mid - 1;
			}
			else {
				st = mid + 1;
			}
		}

		cout << "#" << tc << " ";
		cout << re<<"\n";
		
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	input();
}
