#include<iostream>
#include<vector>
#include<queue>

using namespace std;
struct ticket {
	int v;
	int c;
	int d;
};

vector<vector<ticket>> ticketInfo;
int T, N, M, K,u,v,c,d;
const int MAX = 10'001;
const int INF = 1'000'000'000;
//행은 지원 비용, 열은 노드 
int minDist[MAX][100];

void Solution();

void Input() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> N >> M >> K;
		ticketInfo.clear();
		ticketInfo.resize(N);
		for (int j = 0; j < K; j++) {
			cin >> u >> v >> c >> d;
			ticketInfo[--u].push_back({ --v,c,d });
		}
		Solution();
	}
}
//매 방문마다 현재 비용이 줄어들기 때문에, 다이나믹프로그래밍도 가능하다(knap-sack문제와 유사).
int KCM(int curMoney,int node) {
	int& ret = minDist[curMoney][node];
	if (ret != -1) return ret;
	if (node == N-1) return ret=0;

	ret = INF;
	for (auto& elem : ticketInfo[node]) {
		if (curMoney >= elem.c) ret = min(ret, KCM(curMoney -	 elem.c, elem.v)+elem.d);
	}	
	return ret;
}

void Solution() {
	fill(&minDist[0][0], &minDist[MAX-1][100], -1);

	int Ans = KCM(M, 0);
	if (Ans == INF) cout << "Poor KCM" << '\n';
	else cout << Ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	Input();
}