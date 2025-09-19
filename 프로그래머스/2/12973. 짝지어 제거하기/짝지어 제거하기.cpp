#include <iostream>
#include<string>
#include<stack>
using namespace std;

stack<int> st;
int solution(string s){
	int answer = -1;
	for (auto c : s) {
		int ch = c - 'a';
		if (st.empty())
			st.push(ch);
		else {
			int tp = st.top();
			if (tp == ch)
				st.pop();
			else
				st.push(ch);
		}
	}
	if (st.empty())
		return 1;
	else
		return 0;
	return answer;
}
