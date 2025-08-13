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
using namespace std;

struct State {
	int pre, now;
	int cost;
}heap[100005];
int hs;
void push(State x) {
	int i = hs++;
	while (i) {
		int par = (i - 1) / 2;
		if (heap[par].cost <= x.cost)
			break;
		heap[i] = heap[par];
		i = par;
	}
	heap[i] = x;
}
State pop() {
	State ret = heap[0];
	int i = 0;
	heap[i] = heap[--hs];
	while (1) {
		int le = i * 2 + 1;
		int ri = i * 2 + 2;
		int pr = i;
		if (le < hs&&heap[le].cost < heap[pr].cost)
			pr = le;
		if (ri < hs&&heap[ri].cost < heap[pr].cost)
			pr = ri;
		if (pr == i)
			break;
		swap(heap[pr], heap[i]);
		i = pr;
	}
	return ret;
}
int n, m, k,r;

unordered_map<string, int> citymap;
int cityidx;


vector<int> plan;

double arr[2][105][105];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> r;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if(citymap.find(s)==citymap.end())
			citymap[s] = cityidx++;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		plan.push_back(citymap[s]);
	}

	for (int i = 0; i < cityidx; i++) {
		for (int j = 0; j < cityidx; j++) {
			arr[0][i][j]=arr[1][i][j] = DBL_MAX;
			if (i == j)
				arr[0][i][j]=arr[1][i][j] = 0;
		}
	}

	cin >> k;
	for (int i = 0; i < k;i++) {
		string name, st, en;
		double cost;
		cin >> name >> st >> en >> cost;

		int s, e;
		s = citymap[st];
		e = citymap[en];
		arr[0][e][s]=arr[0][s][e] = min(arr[0][s][e], cost);


		if (name[0] == 'M' || name[0] == 'I')
			arr[1][s][e] = arr[1][e][s] = 0;
		else if (name == "S-Train" || name == "V-Train")
			arr[1][s][e] = arr[1][e][s] = min(arr[1][s][e],cost / 2);
		else
			arr[1][s][e] = arr[1][e][s] = min(arr[1][s][e], cost);
	}

	for (int z = 0; z < cityidx; z++) {
		for (int i = 0; i < cityidx; i++) {
			for (int j = 0; j < cityidx; j++) {
				if (arr[0][i][j] > arr[0][i][z] + arr[0][z][j])
					arr[0][i][j] = arr[0][i][z] + arr[0][z][j];
				if (arr[1][i][j] > arr[1][i][z] + arr[1][z][j])
					arr[1][i][j] = arr[1][i][z] + arr[1][z][j];
			}
		}
	}
/*
	for (auto c : citymap) {
		cout << c.first << ": " << c.second << "\n";
	}
	cout << "\n\n";
	for (int i = 0; i < n; i++)
		cout << setw(4) << i << " ";
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout <<setw(4)<< arr[0][i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << setw(4) << arr[1][i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";

	*/
	double sum0, sum1;
	sum0  = 0;
	sum1 = r;
	for (int i = 0; i < m-1;i++) {
		int st = plan[i];
		int en = plan[i + 1];
		sum0 += arr[0][st][en];
		sum1 += arr[1][st][en];
	}
	//cout << sum0 << " , " << sum1 << "\n";
	if (sum1 < sum0)
		cout << "Yes";
	else
		cout << "No";

}
