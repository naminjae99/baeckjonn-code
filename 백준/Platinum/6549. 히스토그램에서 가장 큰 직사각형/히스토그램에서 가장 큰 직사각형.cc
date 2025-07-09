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
#include<unordered_set>
#include<string>
#include<string.h>
#include <stack>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<long long> height(n);
        for (int i = 0; i < n; ++i) {
            cin >> height[i];
        }

        stack<int> s;
        long long max_area = 0;

        for (int i = 0; i < n; ++i) {
            // 현재 높이가 스택의 top보다 작다면 계산 시작
            while (!s.empty() && height[s.top()] > height[i]) {
                int top = s.top(); s.pop();
                long long width = s.empty() ? i : (i - s.top() - 1);
                max_area = max(max_area, height[top] * width);
            }
            s.push(i);
        }

        // 남은 높이들 처리
        while (!s.empty()) {
            int top = s.top(); s.pop();
            long long width = s.empty() ? n : (n - s.top() - 1);
            max_area = max(max_area, height[top] * width);
        }

        cout << max_area << '\n';
    }

    return 0;
}

