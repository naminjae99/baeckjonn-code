#include <bits/stdc++.h>
using namespace std;

int n, m, in[101010], out[101010], cnt;
vector<int> g[101010];

struct BIT{
	int tree[101010];
	void update(int x, int val){
		for(int i=x; i<=n; i += (i&-i)){
			tree[i] += val;
		}
	}
	int query(int x){
		int ret = 0;
		for(int i=x; i>0; i -= (i&-i)){
			ret += tree[i];
		}
		return ret;
	}
} up, down;

void dfs(int v){
	in[v] = ++cnt;
	for(auto u : g[v]){
		dfs(u);
	}
	out[v] = cnt;
}


int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;

	for(int i=1; i<=n; i++){
		int t; cin >> t;
		if(i == 1) continue;
		g[t].push_back(i);
	}

	dfs(1);

	int flag = 0;
	while(m--){
		int op, x, y; cin >> op;
		if(op == 3) flag ^= 1;
		else if(op == 1){
			cin >> x >> y;
			if(!flag) down.update(in[x], y), down.update(out[x]+1, -y);
			else up.update(in[x], y);
		}else{
			cin >> x;
			int u = up.query(out[x]) - up.query(in[x]-1);
			int d = down.query(in[x]);
			cout << u+d << "\n";
		}
	}
}