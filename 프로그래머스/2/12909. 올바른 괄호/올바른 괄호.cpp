#include<string>
#include <iostream>

using namespace std;
int arr[1000005];
int idx;
bool solution(string s)
{
	bool answer = true;
	idx = -1;
	int ch;

	for (auto c : s) {
		if (c == '(')
			ch = 0;
		else
			ch = 1;

		//스택에 있을떄
		if (idx >= 0) {
			int top = arr[idx];
			if (top == 0) {
				if (ch == 0)
					arr[++idx] = ch;
				else
					idx--;
			}
			else {
				answer = 0;
				break;
			}
		}
		else {
			if (ch == 1) {
				answer = 0;
				break;
			}
			else
				arr[++idx] = ch;
		}
	}

	if (idx != -1)
		answer = 0;
	return answer;
}