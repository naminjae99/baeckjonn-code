#include <vector>
#include <algorithm>

using namespace std;

int max_sheep = 0;
vector<int> adj[18];
vector<int> node_info;

void dfs(int sheep, int wolf, vector<int> next_nodes) {
    max_sheep = max(max_sheep, sheep);

    for (int i = 0; i < next_nodes.size(); i++) {
        int curr = next_nodes[i];
        int ns = sheep + (node_info[curr] == 0);
        int nw = wolf + (node_info[curr] == 1);

        if (ns > nw) {
            // 현재 노드를 제외하고, 현재 노드의 자식들을 추가한 새로운 후보 리스트 생성
            vector<int> next_list = next_nodes;
            next_list.erase(next_list.begin() + i);
            for (int child : adj[curr]) {
                next_list.push_back(child);
            }
            dfs(ns, nw, next_list);
        }
    }
}

int solution(vector<int> info, vector<vector<int>> edges) {
    node_info = info;
    for (auto& edge : edges) {
        adj[edge[0]].push_back(edge[1]);
    }

    vector<int> start_nodes;
    for (int child : adj[0]) {
        start_nodes.push_back(child);
    }

    dfs(1, 0, start_nodes);
    return max_sheep;
}