#include<iostream>
#include<vector>
#include<queue>
#define ll long long
#define INF ((ll)1<<60)
using namespace std;

struct Node{
	ll cost;
	int color;
	bool visited;
	vector<pair<int, ll>> to_node;
} node_id[200005];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, m, c, x, y, w;
	cin >> n >> m >> c;
	for(int i=1; i<=n; i++){
		cin >> node_id[i].color;
		node_id[i].cost = INF;
		node_id[i].visited = false;
	}
	for(int i=0; i<m; i++){
		cin >> x >> y >> w;
		node_id[x].to_node.push_back({y, w});
		node_id[y].to_node.push_back({x, w});
	}
	for(int i=1; i<=n; i++){
		for(auto& e: node_id[i].to_node){
			if(node_id[i].color != node_id[e.first].color){
				node_id[i].cost = min(node_id[i].cost, e.second);
			}
		}
	}
	
	priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> Q;
	for(int i=1; i<=n; i++){
		if(node_id[i].cost != INF){
			Q.push({node_id[i].cost, i});
		}
	}
	while(!Q.empty()){
		ll cost = Q.top().first;
		int now = Q.top().second;
		Q.pop();
		if(node_id[now].visited){
			continue;
		}
		node_id[now].visited = true;
		for(auto& e: node_id[now].to_node){
			if(!node_id[e.first].visited && node_id[now].cost + e.second < node_id[e.first].cost){
				node_id[e.first].cost = node_id[now].cost + e.second;
				Q.push({node_id[e.first].cost, e.first});
			}
		}
	}
	
	for(int i=1; i<=n; i++){
		cout << node_id[i].cost << ' ';
	}
	return 0;
} 
