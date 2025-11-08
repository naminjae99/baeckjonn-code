
#include <bits/stdc++.h>
using namespace std;

extern string submit(int);

int solution(int n) {
    set<int> hold;
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) if (i != j) {
            for (int k = 1; k <= 9; ++k) if (k != i && k != j) {
                for (int w = 1; w <= 9; ++w) if (w != i && w != j && w != k) {
                    int num = i * 1000 + j * 100 + k * 10 + w;
                    hold.insert(num);
                }
            }
        }
    }

    auto check = [](int a, int b, const string& res) -> bool {
        int x = res[0] - 48;
        int y = res[3] - 48;

        int A[] = { a % 10, a / 10 % 10, a / 100 % 10, a / 1000 };
        int B[] = { b % 10, b / 10 % 10, b / 100 % 10, b / 1000 };

        int cnt = 0;
        for (int i = 0; i < 4; ++i) cnt += A[i] == B[i];

        if (x != cnt) return false;

        cnt = 0;
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) if (i != j) {
                cnt += A[i] == B[j];
            }
        }

        return y == cnt;
    };

    for (int i = 0; i < n; ++i) {
        int now = *hold.begin();
        string res = submit(now);

        auto it = hold.begin();
        while (it != hold.end()) {
            int val = *it;
            if (check(now, val, res)) it++;
            else it = hold.erase(it);
        }

        if (hold.size() == 1) {
            return *hold.begin();
        }
    }

    return *hold.begin();
}