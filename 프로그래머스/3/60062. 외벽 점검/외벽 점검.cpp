#include <bits/stdc++.h>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 1e9;
    
    int wSize = weak.size();
    int dSize = dist.size();
    
    // 1️⃣ weak를 2배로 늘려서 원형 → 선형 처리
    vector<int> weak2;
    for (int i = 0; i < wSize; i++)
        weak2.push_back(weak[i]);
    for (int i = 0; i < wSize; i++)
        weak2.push_back(weak[i] + n);

    // 2️⃣ 친구 순열 탐색
    sort(dist.begin(), dist.end());
    
    do {
        // 3️⃣ weak 시작점 고정
        for (int start = 0; start < wSize; start++) {
            
            int cnt = 1; // 현재 투입한 친구 수
            int position = weak2[start] + dist[cnt - 1];
            
            // start부터 wSize만큼 검사
            for (int idx = start; idx < start + wSize; idx++) {
                
                // 현재 친구로 커버 못하면
                if (weak2[idx] > position) {
                    cnt++;  // 친구 추가
                    
                    if (cnt > dSize)
                        break;
                    
                    position = weak2[idx] + dist[cnt - 1];
                }
            }
            
            answer = min(answer, cnt);
        }
        
    } while (next_permutation(dist.begin(), dist.end()));
    
    if (answer > dSize)
        return -1;
    
    return answer;
}
