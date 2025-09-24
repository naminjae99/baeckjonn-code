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
#include<stack>
#include<sstream>
#include<iomanip>
#include<deque>
#include<array>
#include<limits.h>
#include<cfloat>
using namespace std;

unordered_map<string, vector<string>> graph;
vector<string> answer;
vector<string> path;
int ticketCount;
bool finished = false;

void dfs(string cur) {
    path.push_back(cur);

    if (path.size() == ticketCount + 1) {
        answer = path;
        finished = true;
        return;
    }

    for (int i = 0; i < graph[cur].size(); i++) {
        string next = graph[cur][i];
        if (next == "") continue; // 이미 사용한 티켓

        graph[cur][i] = ""; // 사용 처리
        dfs(next);
        if (finished) return; // 첫 번째 완성된 경로가 답
        graph[cur][i] = next; // 되돌리기
    }

    path.pop_back();
}

vector<string> solution(vector<vector<string>> tickets) {
    ticketCount = tickets.size();
    graph.clear();

    // 그래프 구성
    for (auto &t : tickets) {
        graph[t[0]].push_back(t[1]);
    }

    // 사전순 정렬
    for (auto &kv : graph) {
        sort(kv.second.begin(), kv.second.end());
    }

    path.clear();
    dfs("ICN");
    return answer;
}