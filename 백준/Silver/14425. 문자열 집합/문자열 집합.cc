#include<iostream>
#include <unordered_map>
#include<queue>
#include <unordered_set>
#include<string>
using namespace std;

int n, m;
int re;
unordered_set<string> v;
int main() {

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string x;
		cin >> x;
		v.insert(x);
	}
	for (int i = 0; i < m; i++) {
		string x;
		cin >> x;
		if (v.find(x) != v.end())
			re++;
	}
	cout << re;
}