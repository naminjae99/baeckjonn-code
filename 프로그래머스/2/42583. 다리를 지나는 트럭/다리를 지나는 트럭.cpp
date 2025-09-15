#include <string>
#include <vector>
#include<queue>
using namespace std;



int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> wait;
	queue<pair<int, int>> ing;

	for (auto c : truck_weights)
		wait.push(c);

	int sum = 0;
	while (!wait.empty()) {
		answer++;
	    
        //먼저 있던거 통과
		if (ing.size() == bridge_length) {
			answer = ing.front().second + bridge_length;
			sum -= ing.front().first;
			ing.pop();
		}
        
		//다리에 올라가있는 트럭이 탈출하면
		while (!ing.empty()) {
			if (ing.front().second + bridge_length <= answer) {
				sum -= ing.front().first;
				ing.pop();
			}
			else
				break;
		}

		int tp = wait.front();
		wait.pop();

	

		if (sum + tp > weight) {
			while (sum + tp > weight) {
				answer = ing.front().second + bridge_length;
				sum -= ing.front().first;
				ing.pop();
			}
			ing.push({ tp,answer });
			sum += tp;
		}
		else {
			ing.push({ tp,answer });
			sum += tp;
		}
	}
	while (!ing.empty()) {
		answer = ing.front().second + bridge_length;
		ing.pop();
	}

	return answer;
}