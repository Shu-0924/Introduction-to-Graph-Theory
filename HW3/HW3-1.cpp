#include<iostream>
#include<vector>
using namespace std;

struct Node{
	bool visited;
	vector<int> to_node;
} node_id[200005];


void dfs_visit(int now){
	node_id[now].visited = true;
	for(int& next: node_id[now].to_node){
		if(!node_id[next].visited){
			dfs_visit(next);
		}
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, m, x, y;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >>x >> y;
		node_id[x].to_node.push_back(y);
		node_id[y].to_node.push_back(x);
	}
	
	int odd_degree = 0;
	for(int i=1; i<=n; i++){
		odd_degree += node_id[i].to_node.size()%2!=0;
	}
	if(odd_degree!=0 && odd_degree!=2){
		cout << "NO";
		exit(0);
	}
	
	int start=-1;
	for(int i=1; i<=n; i++){
		if(node_id[i].to_node.size()==0){
			node_id[i].visited = true;
		}
		else{
			start = i;
			node_id[i].visited = false;
		}
	}
	dfs_visit(start);
	for(int i=1; i<=n; i++){
		if(!node_id[i].visited){
			cout << "NO";
			exit(0);
		}
	}
	cout << "YES";
	return 0;
}
