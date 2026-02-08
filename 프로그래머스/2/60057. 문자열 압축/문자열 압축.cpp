#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include<iostream>
#include<unordered_map>
#include<set>
#include<vector>
#include<memory.h>
#include<algorithm>
#include<math.h>
#include<queue>
#include<deque>
#include<unordered_set>
#include<string>
#include<string.h>
#include<stack>
#include<sstream>
#include<iomanip>
#include<deque>
#include<array>
#include<limits.h>
#include<cfloat>
#include<map>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;


int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,1,-1 };

int n, m, ret, t;



int solution(string s) {
	n = s.size();
	int answer = n;

	for (int len = 1; len < n; len++) {
		
		int tmp = 0;

		for (int i = 0; i < n; i++) {
			if (i + len - 1 >= n) {
				tmp += (n - i);
				break;
			}
			string cp = s.substr(i, len);

			
			int cnt = 1;
			for (int j = i + len; j <n; j++) {
				if (j + len - 1 >= n)
					break;

				if (cp == s.substr(j, len)) {
				//	cout << j << "부터" << len << "개 부분문자열: " << s.substr(j, len) << "\n";
					cnt++;
					j += len - 1;
				}
				else
					break;
				
			}

			if (cnt == 1) {
				tmp += len;
				i += len - 1;
			}
			else {
				tmp += len;
				if (cnt < 10)
					tmp += 1;
				else if (cnt < 100)
					tmp += 2;
				else if (cnt < 1000)
					tmp += 3;
				else
					tmp += 4;
				i += (len*cnt) - 1;
			}
		//	cout << cp << "가 " << cnt << "개\n";
		}
		//cout << len << "개로 잘랐을떄" << tmp << "\n";
		answer = min(answer, tmp);
	}


	return answer;
}
