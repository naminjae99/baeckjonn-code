#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[1001];

vector <int> t;
int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr, arr + n);

	
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			t.push_back(arr[i] + arr[j]);
		}
	}
	
		sort(t.begin(), t.end());

	for (int i = n-1; i>0; i--) {
		for (int j = 0; j <i; j++) {
			if (binary_search(t.begin(), t.end(), arr[i] - arr[j])) {
				cout << arr[i];
				return 0;
			}
		}
	}
}

