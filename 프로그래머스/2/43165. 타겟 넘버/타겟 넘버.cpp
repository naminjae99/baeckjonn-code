#include <string>
#include <vector>

using namespace std;


int n, m, k, ret, h;

int s;
bool ord[20];
int arr[20];

void dfs(int dep) {
	if (dep == s) {
		int sum = 0;
		for (int i = 0; i < s; i++) {
			if (ord[i]) 
				sum += arr[i];	
			else
				sum -= arr[i];
		}
		if (sum == n)
			ret++;
		return;
	}
	for (int i = 0; i < 2; i++) {
		ord[dep] = i;
		dfs(dep + 1);
	}
}
int solution(vector<int> numbers, int target) {
	n = target;
	s = numbers.size();
	for (int i = 0; i < s; i++)
		arr[i] = numbers[i];
	dfs(0);

	return ret;
}
