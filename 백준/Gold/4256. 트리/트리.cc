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


int arr[1001];

int pre[1001];
int inord[1001];
vector <int> re;

int tofind = 0;
void f(int st ,int en) {
	//pre[root]에 해당하는 값을 inord인덱스 추출
	int x = pre[++tofind];
	int idx;



	for (int i = 1; i <= n; i++) {
		if (inord[i] == x) {
			idx = i;
			break;
		}
	}

	//cout << x << "가 루트가 되고 " << st<<","<<en << " 중위에서 그 위치는 " << idx << "\n";
	
	if (st == en) {
		//cout << "리프노드에 도달하여 " << x << "추가\n\n";
		re.push_back(x);
		return;
	}

	if (idx - 1 >= st) {
		//st~idx-1이 왼쪽 덩어리
		f(st, idx - 1);
	}
	if (idx + 1 <= en) {
		//idx+1 n까지 오른쪽 덩어리
		f(idx + 1, en);
	}
	//cout << x << "추가\n\n";
	re.push_back(x);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> t;

	while (t--) {

		cin >> n;

		tofind = 0;
		memset(pre, 0, sizeof(pre));
		memset(inord, 0, sizeof(inord));
		re.clear();
		for (int i = 1; i <= n; i++) 
			cin >> pre[i];
		for (int i = 1; i <= n; i++)
			cin >> inord[i];

		f(1, n);

		for (auto c : re)
			cout << c << " ";
		cout << "\n";
	}

}
