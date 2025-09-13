#include <iostream>
#include <queue>
#include <memory.h>
#include <vector>
#include <algorithm>

using namespace std;

int r, c, k;
int arr[101][101];
int cnt[101];
int t;
int rn = 3;
int cn = 3;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second != b.second) {
		return a.second < b.second; 
	}
	return a.first < b.first;
}



int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> r >> c >> k;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}



	while (1) {
		if (arr[r - 1][c - 1] == k) {
			cout << t;
			return 0;
		}

		if (t > 100) {
			cout << -1;
			return 0;
		}

		vector <int> Size;

		

		if (rn>=cn) {
			
			for (int i = 0; i < rn; i++) {
				memset(cnt, 0, sizeof(cnt));
				vector<pair<int, int>> q;

				for (int j = 0; j < cn; j++) {
					if (arr[i][j] != 0)
						cnt[arr[i][j]]++;
				}

				for (int j = 1; j <101; j++) {
					if (cnt[j] > 0) {
						q.push_back({ j, cnt[j] });
					}
				}

				sort(q.begin(), q.end(), compare);

				
				int z = 0;
				
				for (int j = 0; j < q.size(); j++) {
					arr[i][z] = q[j].first;
					arr[i][z+1] = q[j].second;
					z += 2;
				}
				while (z < cn) {
					arr[i][z] = 0;
					z++;
				}

				Size.push_back(z);
			}
			sort(Size.begin(), Size.end());
			cn = Size.back();
		}

		else {
			for (int i = 0; i < cn; i++) {
				memset(cnt, 0, sizeof(cnt));
				vector<pair<int, int>> q;

				for (int j = 0; j < rn; j++) {
					if (arr[j][i] != 0)
						cnt[arr[j][i]]++;
				}

				for (int j = 1; j <101; j++) {
					if (cnt[j] > 0) {
						q.push_back({ j, cnt[j] });
					}
				}

				sort(q.begin(), q.end(), compare);

				int z = 0;
			
				for (int j = 0; j < q.size(); j++) {
					arr[z][i] = q[j].first;
					arr[z + 1][i] = q[j].second;
					z += 2;
				}
				for (int k = z; k < rn; k++)
					arr[k][i] = 0;

				Size.push_back(z);
			}

			sort(Size.begin(), Size.end());
			rn = Size.back();
		}

		t++;

	}
	


}