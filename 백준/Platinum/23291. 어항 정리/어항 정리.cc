#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include<iostream>
#include<queue>
#include<vector>
#include<memory.h>
#include<iomanip>
using namespace std;

int n, k;
deque <int> arr[101];
int maxx = -1;
int minn = 100000;
int re;
int tmp_arr[101][101] = { 0, };
int ttmp_arr[101][101] = { 0, };
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };


void pri(int x) {
	for (int i = x; i >= 0; i--) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}
void add1() {
	for (int i = 0; i < arr[0].size(); i++) {
		if (arr[0][i] == minn)
			arr[0][i]++;
	}
}
pair<int,int> turn90() {
	int top = 1;
	int two = 0;

	vector <int> v;
	arr[1].push_back(arr[0].front());
	arr[0].pop_front();


/*
	cout << "two top" << two << ". " << top << "\n";
	pri(top);

*/
	while (1) {
		int ss = arr[0].size();
		if (ss - two - top - 2 < 0) {
			return { two,top };
		}
		
		
		int s;
		for (int i = 0;i <= two;i++) {
			for (int j = 0; j <= top; j++) {
				v.push_back(arr[j].front());
				arr[j].pop_front();
			}
			s = v.size();
			for (int j = 0; j < s; j++) {
				arr[-i+two + 1].push_back(v[j]);
			}
			v.clear();
		}
		top = two + 1;
		two = s-1;
		/*
		
		cout << "two top" << two << ". " << top << "\n";
		pri(top);
		*/
	}
}

void move(int x) {

	for (int i = 0; i <= x; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			tmp_arr[i][j] = arr[i][j];
		}
	}

	memcpy(ttmp_arr, tmp_arr, sizeof(tmp_arr));

	for (int i = 0; i <= x; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			for (int z = 0; z < 4; z++) {
				int nx = i + dx[z];
				int ny = j + dy[z];
				if (nx<0 || nx>x || ny < 0 || ny >= arr[nx].size())
					continue;
				int dif = (tmp_arr[i][j] - tmp_arr[nx][ny])/5;
				if (dif> 0) {
					ttmp_arr[i][j] -= dif;
					ttmp_arr[nx][ny] += dif;
				}
			}
		}
	}
	for (int i = 0; i <= x; i++) {
		int s = arr[i].size();
		arr[i].clear();
		for (int j = 0; j < s; j++) {
			arr[i].push_back(ttmp_arr[i][j]);
		}
	}
}
void remove(pair<int,int> ttt){
	int top = ttt.second;
	int two = ttt.first;
	vector<int> v;
	for (int i = 0; i <= two; i++) {
		for (int j = 0; j <= top; j++) {
			v.push_back(arr[j].front());
			arr[j].pop_front();
		}
	}
	for (int i = v.size() - 1; i >= 0; i--)
		arr[0].push_front(v[i]);
	v.clear();
	
	
	for (int i = 0; i < n / 2; i++) {
		v.push_back(arr[0].front());
		arr[0].pop_front();
	}
	for (int i = 0; i < n/2; i++) {
		arr[1].push_front(v[i]);
	}
	v.clear();
	
	for (int i = 0; i < n / 4; i++) {
		v.push_back(arr[0].front());
		arr[0].pop_front();
	}
	for (int i = 0; i < n / 4; i++) {
		arr[3].push_front(v[i]);
	}
	v.clear();
	for (int i = 0; i < n / 4; i++) {
		v.push_back(arr[1].front());
		arr[1].pop_front();
	}
	for (int i = 0; i < n / 4; i++) {
		arr[2].push_front(v[i]);
	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr[0].push_back(x);
		if (x < minn)
			minn = x;
		if (x > maxx)
			maxx = x;
	}
	while (1) {
		if (maxx - minn <= k)
			break;
		re++;
		add1();
/*

		cout << "1더하기\n";
		pri(0);

*/
		pair<int,int> tt=turn90();
	/*
			cout << "물고기이동\n";
		pri(2);

*/
		move(tt.second);
	/*
		cout << "물고기이동\n";
		pri(2);

*/
		remove(tt);
		/*
		cout << "재배치\n";
		pri(3);

*/
		move(3);
		/*
		cout << "물고기이동2\n";
		pri(3);
		*/

		vector<int> v;
		for (int i = 0; i < n / 4; i++) {
			for (int j = 0; j < 4; j++) {
				v.push_back(arr[j].front());
				arr[j].pop_front();
			}
		}
		
		minn = 987654321;
		maxx = -1;
		for (int i = 0; i < v.size(); i++) {
			arr[0].push_back(v[i]);
			if (minn > v[i])
				minn = v[i];
			if (maxx < v[i])
				maxx = v[i];
		}
		/*
		cout << "마지막펴기\n";
		pri(0);
*/
	}
	cout << re;
}


