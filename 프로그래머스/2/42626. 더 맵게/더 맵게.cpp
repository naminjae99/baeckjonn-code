#include <string>
#include <vector>

using namespace std;
using ll = long long;
int hs;
ll heap[50000005];
void push(ll x) {
	int i = hs++;
	while (i) {
		int par = (i - 1) / 2;
		if (heap[par] <= x)
			break;
		heap[par] = heap[i];
		i = par;
	}
	heap[i] = x;
}
ll pop() {
	ll re = heap[0];
	int i = 0;
	heap[i] = heap[--hs];

	while (1) {
		int le = i * 2 + 1;
		int ri = i * 2 + 2;
		int pr = i;
		if (le < hs&&heap[le] < heap[pr])
			pr = le;
		if (ri < hs&&heap[ri] < heap[pr])
			pr = ri;
		if (pr == i)
			break;
		swap(heap[pr], heap[i]);
		i = pr;
	}
	return re;
}
int solution(vector<int> scoville, int K) {
	int answer = 0;
	for (auto c : scoville)
		push((ll)c);

	while (hs) {
		ll x = pop();
		if (x >= K)
			return answer;
		if (hs<=0) 
			return -1;
		
		ll y = pop();
		answer++;
		push((ll)(x + y*2));
	}
	return answer;
}
