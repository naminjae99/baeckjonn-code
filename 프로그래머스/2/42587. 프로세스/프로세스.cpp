#include <string>
#include <vector>

using namespace std;


int qx[1000005];
int qy[1000005];
int fr, ba;
int cnt[15];

int solution(vector<int> priorities, int location) {
	for (int i = 0; i < priorities.size();i++) {
		int x = priorities[i];
		cnt[x]++;
		qx[ba] = x;
		qy[ba++] = i;
	}
	int answer = 1;

	while (fr < ba) {
		int x = qx[fr];
		int idx = qy[fr++];

		bool flag = 0;
		for (int i = x + 1; i <= 9; i++) {
			if (cnt[i]) {
				flag = 1;
				break;
			}
		}
		//큰거 존재
		if (flag) {
			qx[ba] = x;
			qy[ba++] = idx;
		}
		else {
			if (idx == location) 
				break;
			answer++;
			cnt[x]--;
		}
	}
	return answer;
}