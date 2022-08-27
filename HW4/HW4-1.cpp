#include<iostream>
#include<vector>
#define ll long long
using namespace std;

struct Node{
	int cost;
	vector<int> to_node;
} node_id[200005];

// pair<with_this_node, without_this_node>
pair<ll, ll> dfs_compute(int now, int parent, bool with_cost){
	pair<ll, ll> ret = {node_id[now].cost, 0};
	if(with_cost == false){
		ret.first = 1;
	}
	for(int& next: node_id[now].to_node){
		if(next!=parent){
			pair<ll, ll> child_cover = dfs_compute(next, now, with_cost);
			ret.first += min(child_cover.first, child_cover.second);
			ret.second += child_cover.first;
		}
	}
	return ret;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, x, y;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> node_id[i].cost;
	}
	for(int i=0; i<n-1; i++){
		cin >> x >> y;
		node_id[x].to_node.push_back(y);
		node_id[y].to_node.push_back(x);
	}
	
	pair<ll, ll> a = dfs_compute(1, 1, true);
	pair<ll, ll> b = dfs_compute(1, 1, false);
	cout << min(a.first, a.second) << ' ' << min(b.first, b.second);
	return 0;
}
