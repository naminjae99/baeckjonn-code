#include <iostream>
#include <deque>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;
int arr[100001];


int n, k;
void bfs(int n) {
	deque <int> q;
	q.push_back(n);
	arr[n] = 1;

	while (!q.empty()) {
		int x = q.front();
		q.pop_front();

		if (x == k) {
			cout << arr[x]-1;
			return;
		}

		if (x *2< 100001 && arr[x * 2] == 0) {
			q.push_front(2 * x);
			arr[x * 2] = arr[x];
		}

		if (x >= 1&&arr[x-1]==0) {
			q.push_back( x - 1 );
			arr[x - 1] = arr[x] + 1;
		}

		if (x < 100000 && arr[x + 1] == 0) {
			q.push_back( x + 1 );
			arr[x + 1] = arr[x] + 1;
		}
		
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> n >> k;
	bfs(n);

	
}