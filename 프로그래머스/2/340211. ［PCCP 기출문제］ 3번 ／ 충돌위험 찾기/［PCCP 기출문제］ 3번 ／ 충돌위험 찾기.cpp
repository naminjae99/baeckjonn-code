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
#include<deque>
#include<unordered_set>
#include<string>
#include<string.h>
#include<stack>
#include<sstream>
#include<iomanip>
#include<deque>
#include<array>
#include<limits.h>
#include<cfloat>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;

int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int n, m, ret, k, t, h, w;

pair<int, int> xy[105];

//x번 로봇의 목표 장소
int mok[105];
pair<int, int> now[105];



unordered_map<int, int> mp;

int finish[105];

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
	for (int i = 0; i < points.size(); i++) {
		xy[i + 1] = { points[i][0],points[i][1] };
	}

	//로봇갯수
	n = routes.size();


	for (int i = 0; i < n; i++) {
		int x = routes[i][0];

		now[i] = xy[x];
		//1번 xy를 목표로 가야함
		mok[i] = 1;
		mp[xy[x].first*1000+xy[x].second]++;
	}
	for (auto c : mp) {
		if (c.second > 1)
			ret++;
	}
	


	while (1) {
		mp.clear();

		bool flag = 0;

		for (int i = 0; i < n; i++) {
			int x = now[i].first;
			int y = now[i].second;

			if (finish[i])
				continue;

			flag = 1;


			int mx = xy[routes[i][mok[i]]].first;
			int my = xy[routes[i][mok[i]]].second;

			//cout << i << "번 로봇 현재위치: " << x << ", " << y << "\n";
			//cout << mok[i] << "번 좌표로 가기위함(" << mx << "," << my << ")\n";
			int dis = abs(x - mx) + abs(y - my);

			for (int d = 0; d < 4; d++) {
				int nx = x + dx[d];
				int ny = y + dy[d];
				if (nx < 1 || nx>100 || ny < 1 || ny>100)
					continue;
				if ((abs(nx - mx) + abs(ny - my)) < dis) {
					now[i] = { nx,ny };
					mp[nx*1000+ny]++;
					if (nx == mx && ny == my)
						mok[i]++;
					//	cout << nx << "," << ny << "로 이동했음\n";
					if (mok[i] == routes[i].size()) {
						finish[i] = 1;
					}
					break;
				}
			}



		}

		if (flag == 0)
			break;



		for (auto c : mp) {
			if (c.second > 1)
				ret++;
		}
	}


	return ret;
}
