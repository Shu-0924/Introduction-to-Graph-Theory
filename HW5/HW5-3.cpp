#include <bits/stdc++.h>
#define pii pair<int, int>
#define pb push_back
#define all(x) (x).begin(),(x).end() 
using namespace std;

vector<bool> edge;

struct Node {
	bool exist;
	vector<pii> to_node;
} node_id[200005];
int parent[200005];
int max_size = 1;
int remain = 0;

int get_root(int a) {
	if (parent[a] < 0) {
		return a;
	}
	return parent[a] = get_root(parent[a]);
}

bool join(int a, int b) {
	int root_a = get_root(a);
	int root_b = get_root(b);
	if (root_a != root_b) {
		if (parent[root_a] <= parent[root_b]) {
			parent[root_a] += parent[root_b];
			parent[root_b] = root_a;
			max_size = max(max_size, -parent[root_a]);
		}
		else {
			parent[root_b] += parent[root_a];
			parent[root_a] = root_b;
			max_size = max(max_size, -parent[root_b]);
		}
		remain--;
		return true;
	}
	return false;
}

int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n, m, k, type, x, y;
	cin >> n >> m >> k;
	for(int i=0; i<m; i++) {
		cin >> x >> y;
		node_id[x].to_node.pb({ y, edge.size() });
		node_id[y].to_node.pb({ x, edge.size() });
		edge.pb(true);
	}
	for (int i=1; i<=n; i++) {
		node_id[i].exist = true;
		sort(all(node_id[i].to_node));
	}

	vector<pair<int, vector<pii>>> D;
	for(int i=0; i<k; i++) {
		cin >> type;
		if (type == 1) {
			cin >> x >> y;
			edge[lower_bound(all(node_id[x].to_node), make_pair(y, 0))->second] = false;
			D.pb({ -1, vector<pii>(1, {x, y})});
		}
		else {
			cin >> x;
			node_id[x].exist = false;
			vector<pii> v;
			for(auto& ii: node_id[x].to_node) {
				if (edge[ii.second]) {
					edge[ii.second] = false;
					v.pb({ x, ii.first });
				}
			}
			D.pb({ x, v });
		}
	}
	for (int i=1; i<=n; i++) {
		parent[i] = -1;
		if (node_id[i].exist) {
			remain++;
		}
	}
	for (int i=1; i<=n; i++) {
		if (!node_id[i].exist) {
			continue;
		}
		for(auto& ii: node_id[i].to_node) {
			if (edge[ii.second] && node_id[ii.first].exist) {
				join(i, ii.first);
			}
		}
	}

	stack<pii> output;
	for (int i=D.size()-1; i>=0; i--) {
		output.push({ remain, max_size });
		if (D[i].first == -1) {
			join(D[i].second[0].first, D[i].second[0].second);
		}
		else {
			remain++;
			node_id[D[i].first].exist = true;
			for(auto& ii: D[i].second) {
				join(ii.first, ii.second);
			}
		}
	}
	while (!output.empty()) {
		cout << output.top().first << ' ' << output.top().second << '\n';
		output.pop();
	}
	return 0;
}
