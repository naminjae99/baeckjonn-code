#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, const char * argv[])
{
    int N;
    cin >> N;
    
    vector<int> numbers(N, 0);
    for (int i = 0; N > i; i++)
        cin >> numbers[i];
    
    vector<int> LIS(1, 0);
    LIS.emplace_back(numbers[0]);
    for (int i = 1; numbers.size() > i; i++)
    {
        if (LIS.back() < numbers[i])
            LIS.emplace_back(numbers[i]);
        else
        {
            //현재 원소보다 크거나 같은 숫자가 나오는 첫번째 인덱스를 찾기 위해 
            //lower_bound 함수 사용 
            int index = distance(LIS.begin(), 
                lower_bound(LIS.begin(), LIS.end(), numbers[i]));
            LIS[index] = numbers[i];
        }
    }
    
    int answer = LIS.size() - 1;
    cout << answer;
    
    return 0;
}
