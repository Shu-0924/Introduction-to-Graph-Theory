#include<iostream>
#include<vector>
#define ll long long
#define MOD 1000000007
using namespace std;

struct Node{
	bool visited;
	vector<int> to_node;
} node_id[200005];

pair<ll, ll> dfs(int u){
	node_id[u].visited = true;
	ll with_u = 1, not_with_u = 0;
	for(int& v: node_id[u].to_node){
		if(!node_id[v].visited){
			pair<ll, ll> result = dfs(v);
			with_u = with_u * (result.first + 1) % MOD;
			not_with_u += result.first + result.second;
		}
	}
	return {with_u, not_with_u % MOD};
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, x, y;
	cin >> n;
	for(int i=1; i<=n; i++){
		node_id[i].visited = false;
	}
	for(int i=0; i<n-1; i++){
		cin >> x >> y;
		node_id[x].to_node.push_back(y);
		node_id[y].to_node.push_back(x);
	}
	
	pair<ll, ll> result = dfs(1);
	cout << (result.first + result.second) % MOD;
	return 0;
}
