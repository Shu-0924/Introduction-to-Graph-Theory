#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Node{
	int distance;
	vector<int> to_node;
} node_id[200005];


int bfs_compute(int start, int n){
	for(int i=1; i<=n; i++){
		node_id[i].distance = -1;
	}
	node_id[start].distance = 0;
	
	int now;
	queue<int> Q;
	Q.push(start);
	while(!Q.empty()){
		now = Q.front();
		Q.pop();
		for(int& next: node_id[now].to_node){
			if(node_id[next].distance == -1){
				node_id[next].distance = node_id[now].distance+1;
				Q.push(next);
			}
		}
	}
	return now;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);	
	
	int n, u, v;
	cin >> n;
	for(int i=0; i<n-1; i++){
		cin >> u >> v;
		node_id[u].to_node.push_back(v);
		node_id[v].to_node.push_back(u);
	}
	
	cout << node_id[bfs_compute(bfs_compute(1, n), n)].distance;
	return 0;
}
