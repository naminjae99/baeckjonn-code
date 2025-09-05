#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
#include <math.h>

using namespace std;
int n;
int result = 987654321;
int arr[21][21];

int vis[21];
//temas cnt-temas

void f(int ind,int dep) {
	if (dep== n / 2) {
		int t1=0;
		int t2 = 0;
		
		for (int i = 1; i <=n; i++) {
			for (int j = 1; j <= n; j++) {
				if (vis[i] == 1 && vis[j] == 1) {
					t1 += arr[i][j];
				}
				if (vis[i] == 0 && vis[j] == 0) {
					t2 += arr[i][j];
				}
			}
		}

		int dif = abs(t1-t2);
		result = min(result,dif);
		
		return;
	}

	for (int i = ind; i < n; i++) {
		if (vis[i] == 1)
			continue;

	
		vis[i] = 1;
		f(i+1,dep+1);

		vis[i] = 0;

	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		
		}
	}
	f(1,0);
	cout << result;
}