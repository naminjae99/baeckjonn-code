#include <string>
#include <vector>

using namespace std;

int arr[105];

vector<int> solution(vector<int> progresses, vector<int> speeds) {
	int idx = 0;
	for (auto c : progresses) {
		int s = speeds[idx];
		arr[idx++] = ((100 - c) + s-1) / s;
	}
	vector<int> answer;
	int mx = 0;
	int cnt = 0;
	for (int i = 0; i < idx; i++) {
		if (mx == 0) {
			mx = arr[i];
			cnt = 1;
		}
		else{
			if (arr[i] <= mx) {
				cnt++;
			}
			else {
				answer.push_back(cnt);
				mx = arr[i];
				cnt = 1;
			}
		}
	}
	answer.push_back(cnt);


	return answer;
}