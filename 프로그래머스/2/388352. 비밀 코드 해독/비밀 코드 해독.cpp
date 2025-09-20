#include <string>
#include <vector>

using namespace std;

int lim,qs;
int ord[5];
int arr[15][5];
int dap[15];
int ret;
void dfs(int dep,int idx) {
	if (dep == 5) {
		bool flag = 0;
		for (int i = 0; i < qs; i++) {
			int tmp = 0;
			for (int j = 0; j < 5; j++) {
				for (int z = 0; z < 5; z++) {
					if (ord[j] == arr[i][z]) {
						tmp++;
						break;
					}
				}
			}
			if (tmp != dap[i]) {
				flag = 1;
				break;
			}		
		}
		if (flag == 0)
			ret++;
		return;
	}
	for (int i = idx; i <= lim; i++) {
		ord[dep] = i;
		dfs(dep + 1, i + 1);
	}
}
int solution(int n, vector<vector<int>> q, vector<int> ans) {
	lim = n;
	qs = q.size();
	for (int i = 0; i < qs; i++) {
		for (int j = 0; j < 5; j++)
			arr[i][j] = q[i][j];
		dap[i] = ans[i];
	}
	dfs(0,1);


	
	return ret;
}