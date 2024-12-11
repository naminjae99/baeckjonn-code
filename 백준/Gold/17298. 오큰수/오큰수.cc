#include <iostream>
#include <deque>
#include<stack>
#include<vector>
using namespace std;

stack <pair<int,int>> s;
int n;
int re[1000005];
int main()
{
	cin >> n;

	int prei = 0;
	int prev = 0;
	int xx;
	cin >> xx;
	s.push({ 1,xx });

	for (int i = 2; i <= n; i++) {
		int x;
		cin >> x;

		while (1) {
			if (s.empty() == 1)
				break;
			if (s.top().second < x) {
				re[s.top().first] = x;
				s.pop();
			}
			else
				break;
		}
		s.push({ i,x });

	}

	s.pop();
	re[n] = -1;

	while (!s.empty()) {
		int a = s.top().first;
		re[a] = -1;
		s.pop();
	}
	for (int i = 1; i <=n; i++) {
		cout << re[i] << " ";
	}
}