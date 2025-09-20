#include <string>
#include <vector>

using namespace std;

int par[205];
int find(int x) {
	if (par[x] == x)
		return x;
	return par[x] = find(par[x]);
}
void uni(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return;
	par[b] = a;
}
int solution(int n, vector<vector<int>> computers) {
	for (int i = 0; i < n; i++)
		par[i] = i;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (computers[i][j]) {
				uni(i, j);
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < n; i++) {
		if (i == par[i])
			answer++;
	}
	return answer;
}