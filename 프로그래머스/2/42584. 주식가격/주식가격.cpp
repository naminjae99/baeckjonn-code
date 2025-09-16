#include <string>
#include <vector>
#include<stack>
#include<memory.h>
using namespace std;

int n;
vector<int> solution(vector<int> prices) {
	vector<int> answer;

	int tmp[100005];
	memset(tmp, -1, sizeof(tmp));
    
	n = prices.size();
	stack<int> s;
	for (int i = n - 1;i>=0; i--) {
		int x = prices[i];

		int tp;
		while (!s.empty() && prices[s.top()] >= x) {
			s.pop();
		}
		if (!s.empty()) {
			tmp[i] = s.top();
		}
		s.push(i);
	}

	for (int i = 0; i < n;i++) {
		if (tmp[i] == -1)
			answer.push_back ( n - 1 - i);
		else
			answer.push_back(tmp[i] - i);
	}

	return answer;
}