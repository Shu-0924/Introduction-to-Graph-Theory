#include<iostream>
#include<vector>
#include<queue>
#define ll long long
using namespace std;

struct Node{
	ll cost;
	bool visited;
	vector<pair<int, ll>> to_node;
} node_id[200005];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, m, x, y, w;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> node_id[i].cost;
		node_id[i].visited = false;
	}
	for(int i=0; i<m; i++){
		cin >> x >> y >> w;
		node_id[x].to_node.push_back({y, w});
		node_id[y].to_node.push_back({x, w});
	}
	
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
	for(int i=1; i<=n; i++){
		Q.push({node_id[i].cost, i});
	}
	while(!Q.empty()){
		ll cost = Q.top().first;
		int now = Q.top().second;
		Q.pop();
		if(node_id[now].visited){
			continue;
		}
		node_id[now].visited = true;
		for(pair<int, ll>& p: node_id[now].to_node){
			if(cost + p.second < node_id[p.first].cost){
				node_id[p.first].cost = cost + p.second;
				Q.push({node_id[p.first].cost, p.first});
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		cout << node_id[i].cost << ' ';
	}
	return 0;
}
