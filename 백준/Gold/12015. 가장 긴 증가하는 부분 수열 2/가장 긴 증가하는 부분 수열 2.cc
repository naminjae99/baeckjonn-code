#include <iostream>
#include <vector>
#include <algorithm> // for lower_bound

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    vector<int> LIS;

    for (int i = 0; i < N; ++i) {
        // 현재 숫자 num에 대해 LIS에서의 위치 찾기
        int num = nums[i];
        auto pos = lower_bound(LIS.begin(), LIS.end(), num);

        if (pos == LIS.end()) {
            // num이 LIS의 끝에 추가될 경우
            LIS.push_back(num);
        } else {
            // 그렇지 않으면, 찾은 위치에 num을 덮어쓰기
            *pos = num;
        }
    }

    // LIS의 길이가 정답
    cout << LIS.size() << endl;

    return 0;
}
