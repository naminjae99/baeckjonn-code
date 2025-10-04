#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
#include <algorithm>
#include <cstring>
#include <numeric>

using namespace std;

const int MAX_N_SIZE = 100005;
const int MAX_GROUP_ARRAY_SIZE = 200002;
const int MAX_TREE_ARRAY_SIZE = 400004;
const int ALPHA_LEN = 26;

int N, M;
int current_groupId = 0;
vector<int> codes;

int seg[ALPHA_LEN][MAX_TREE_ARRAY_SIZE];
int lazy[ALPHA_LEN][MAX_TREE_ARRAY_SIZE];
int par[ALPHA_LEN][MAX_GROUP_ARRAY_SIZE];

//char gr_index -> group_num
vector<int> groups_arr[ALPHA_LEN];
unordered_map<int, int> mp_map[ALPHA_LEN];

int find_root_idx(int c, int x) {
	if (par[c][x] == x) return x;
	return par[c][x] = find_root_idx(c, par[c][x]);
}

void updateLazy(int c, int node, int s, int e) {
	if (lazy[c][node] != 0) {
		seg[c][node] = lazy[c][node];
		if (s != e) {
			lazy[c][node * 2] = lazy[c][node];
			lazy[c][node * 2 + 1] = lazy[c][node];
		}
		lazy[c][node] = 0;
	}
}

void update_range(int c, int node, int s, int e, int l, int r, int val) {
	updateLazy(c, node, s, e);
	if (l > e || r < s) return;
	if (l <= s && e <= r) {
		seg[c][node] = val;
		if (s != e) {
			lazy[c][node * 2] = val;
			lazy[c][node * 2 + 1] = val;
		}
		return;
	}
	int mid = (s + e) / 2;
	update_range(c, node * 2, s, mid, l, r, val);
	update_range(c, node * 2 + 1, mid + 1, e, l, r, val);
	seg[c][node] = max(seg[c][node * 2], seg[c][node * 2 + 1]);
}

int query_idx(int c, int node, int s, int e, int idx) {
	updateLazy(c, node, s, e);
	if (idx < s || idx > e) return 0;
	if (s == e) return seg[c][node];
	int mid = (s + e) / 2;
	return max(query_idx(c, node * 2, s, mid, idx),
		query_idx(c, node * 2 + 1, mid + 1, e, idx));
}

int register_group(int c, int id) {
	if (mp_map[c].find(id) == mp_map[c].end()) {
		groups_arr[c].push_back(id);
		int newIndex = groups_arr[c].size() - 1;
		mp_map[c][id] = newIndex;
		if (newIndex < MAX_GROUP_ARRAY_SIZE) {
			par[c][newIndex] = newIndex;
		}
		return newIndex;
	}
	return mp_map[c].at(id);
}

int getGroupId(int c, int x) {
	int updateIndex = query_idx(c, 1, 1, N, x);
	int repIndex = find_root_idx(c, updateIndex);
	if (repIndex >= groups_arr[c].size()) return 0;
	return groups_arr[c][repIndex];
}

void uni_op(int c, int gx, int gy) {
	if (mp_map[c].find(gy) == mp_map[c].end()) return;

	int xIndex = register_group(c, gx);
	int yIndex = mp_map[c].at(gy);

	int xRoot = find_root_idx(c, xIndex);
	int yRoot = find_root_idx(c, yIndex);

	if (xRoot != yRoot) {
		par[c][yRoot] = xRoot;
	}
}

void move_group_op(int c, int x, int newGroup) {
	if (!mp_map[c].count(x)) return;

	int idx = find_root_idx(c, mp_map[c].at(x));
	int oldGroup = groups_arr[c][idx];

	groups_arr[c][idx] = newGroup;
	mp_map[c].erase(oldGroup);
	mp_map[c][newGroup] = idx;
}

void move_range_op(int c, int l, int r, int newGroup) {
	int idx = register_group(c, newGroup);
	update_range(c, 1, 1, N, l, r, idx);
}

vector<string> solution(string s, vector<string> query) {
	N = s.size();M = query.size();codes.resize(N);
	for (int i = 0; i < N; i++)	codes[i] = s[i] - 'a';

	for (int c = 0; c < ALPHA_LEN; ++c) {
		groups_arr[c].push_back(0);
		mp_map[c][0] = 0;
		for (int i = 0; i < MAX_GROUP_ARRAY_SIZE; ++i)
			par[c][i] = i;
	}
	vector<string> answer;

	for (auto &q : query) {
		stringstream ss(q);vector<string> tok;string temp;while (ss >> temp) tok.push_back(temp);string type = tok[0];

		if (type == "1") {
			int x = stoi(tok[1]);
			int y = stoi(tok[2]);
			int gx = getGroupId(codes[x - 1], x);
			int gy = getGroupId(codes[y - 1], y);
			answer.push_back(gx == gy ? "YES" : "NO");
		}
		else if (type == "2") {
			int x = stoi(tok[1]);string word = tok[2];unordered_set<int> st;
			for (char c : word) st.insert(c - 'a');

			int gx = getGroupId(codes[x - 1], x);

			current_groupId++;
			for (int ch : st)
				move_group_op(ch, gx, current_groupId);
		}
		else if (type == "3") {
			int x = stoi(tok[1]);
			int y = stoi(tok[2]);
			string word = tok[3];
			unordered_set<int> st;
			for (char c : word) st.insert(c - 'a');

			current_groupId++;
			for (int ch : st)
				move_range_op(ch, x, y, current_groupId);
		}
		else if (type == "4") {
			int x = stoi(tok[1]);
			int y = stoi(tok[2]);

			int gx = getGroupId(codes[x - 1], x);
			int gy = getGroupId(codes[y - 1], y);

	
			if (gx > gy) swap(gx, gy);

			for (int c = 0; c < ALPHA_LEN; ++c)
				uni_op(c, gx, gy);
		}
		else if (type == "5") {
			vector<vector<int>> arr(current_groupId + 1, vector<int>(26, 0));

			for (int i = 1; i <= N; i++) {
				int alpha = codes[i - 1];
				int gid = getGroupId(alpha, i);
				arr[gid][alpha]++;
			}

			for (int gid = 0; gid <= current_groupId; ++gid) {
				stringstream sb;
				bool has = false;
				for (int i = 0; i < 26; i++) {
					if (arr[gid][i] > 0) {
						sb << (char)('a' + i) << " " << arr[gid][i] << " ";
						has = true;
					}
				}
				if (has) {
					string res = sb.str();
					if (!res.empty()) res.pop_back();
					answer.push_back(res);
				}
			}
		}
	}

	return answer;
}