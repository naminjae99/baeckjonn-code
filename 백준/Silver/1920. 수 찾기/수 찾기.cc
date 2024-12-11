#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n,m;
vector <int> v;


int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	
	for (int i = 1; i <= n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	cin >> m;

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		bool re = binary_search(v.begin(), v.end(), x);
		cout << re<<"\n";
	}
}