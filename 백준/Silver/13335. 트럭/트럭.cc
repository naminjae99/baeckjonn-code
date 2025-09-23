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
#include<deque>
#include<array>
#include<cfloat>
using namespace std;
using ll = long long;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int n, t, m;
ll ret;
queue<int> wait;
queue<pair<int, ll>> ing;
int bridge_length, weight;

void input() {
	cin >> n >> bridge_length >> weight;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		wait.push(x);
	}
}


void solve() {
	ll sum = 0;
	ll time = 0;
	while (!wait.empty()) {
		time++;
		//L개 트럭이 이미있는경우
		if (ing.size() == bridge_length) {
			time = ing.front().second + bridge_length;
			sum -= ing.front().first;
			ing.pop();
		}

		//다리에 올라가있는 트럭이 탈출하면
		while (!ing.empty()) {
			if (ing.front().second + bridge_length <= time) {
				sum -= ing.front().first;
				ing.pop();
			}
			else
				break;
		}

		int tp = wait.front();
		wait.pop();

		
		//먼저 있던거 통과
		if (sum + tp > weight) {
			while (sum + tp > weight) {
				time = ing.front().second + bridge_length;
				sum -= ing.front().first;
				ing.pop();
			}
			ing.push({ tp,time });
			sum += tp;
		}
		else {
			ing.push({ tp,time });
			sum += tp;
		}
	}
	while (!ing.empty()) {
		time = ing.front().second + bridge_length;
		ing.pop();
	}
	ret= (ll)time;

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	input();
	solve();

	cout << ret;

}
