#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    while (n--) {
        long long x, y;
        cin >> x >> y;
        
        long long d = y - x; // 두 점 사이의 거리
        long long k = 0;

        // k를 증가시키면서, k(k + 1) >= d인 k를 찾는다.
        while (k * (k + 1) < d) {
            k++;
        }
        
        // k * k >= d라면 2 * k - 1번 이동이 최소
        if (k * k >= d) {
            cout << 2 * k - 1 << '\n';
        } 
        // 그렇지 않다면 2 * k번 이동이 최소
        else {
            cout << 2 * k << '\n';
        }
    }

    return 0;
}
