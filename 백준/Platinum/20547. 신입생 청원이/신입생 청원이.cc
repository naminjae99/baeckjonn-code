#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <string>
#include <memory.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <string.h>
#include <set>
#include <iomanip>
#include <unordered_set>
#include <map>
#include<cfloat>
#include<sstream>
#include<numeric>
#include <limits>
using namespace std;
using ll = long long;



struct Lecture {
	string name;
	int start, end, idx;
};

// HH:mm → 분
int timeToMin(const string &s) {
	return stoi(s.substr(0, 2)) * 60 + stoi(s.substr(3, 2));
}
// 분 → HH:mm
string minToTime(int t) {
	char buf[6];
	sprintf(buf, "%02d:%02d", t / 60, t % 60);
	return string(buf);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
	cin >> N >> M;
	vector<Lecture> lec(N);
	map<string, int> mp;

	for (int i = 0; i < N; i++) {
		string name, xs, xe;
		cin >> name >> xs >> xe;
		lec[i] = { name, timeToMin(xs), timeToMin(xe), i };
		mp[name] = i;
	}

	vector<vector<int>> dist(N, vector<int>(N, 1e9));
	for (int i = 0; i < N; i++) dist[i][i] = 0;

	for (int i = 0; i < M; i++) {
		string a, b, zstr;
		cin >> a >> b >> zstr;
		int zh = stoi(zstr.substr(0, 2));
		int zm = stoi(zstr.substr(3, 2));
		int z = zh * 60 + zm;
		int u = mp[a], v = mp[b];
		dist[u][v] = min(dist[u][v], z);
		dist[v][u] = min(dist[v][u], z);
	}

	// 플로이드–워셜: 모든 강의실 간 최단 이동 시간
	for (int k = 0; k < N; k++)
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	// 시작 시간, 이름 기준 정렬
	sort(lec.begin(), lec.end(), [](const Lecture &a, const Lecture &b) {
		if (a.start != b.start) return a.start < b.start;
		return a.name < b.name;
	});

	// 첫 강의: 가장 빨리 시작하는 강의



	vector<int> dp(N, 0);
	dp[0] = lec[0].end - lec[0].start;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (dp[j] == 0) continue; // 아직 도달 불가
			int travel = dist[lec[j].idx][lec[i].idx];
			int arrive = lec[j].end + travel;
			int attend = lec[i].end - max(arrive, lec[i].start);
			if (attend > 0)
				dp[i] = max(dp[i], dp[j] + attend);
		}
	}

	int ans = *max_element(dp.begin(), dp.end());
	cout << minToTime(ans) << "\n";
}


