#include<iostream>
#include<vector>
using namespace std;

struct Edge{
	int cap;
	int res;
	Edge(int c, int r) : cap(c), res(r) {}
};
vector<Edge> edge_id;

struct Node{
	int visited;
	vector<pair<int, int>> to_node;
} node_id[4005];


int v_flag = 1;
bool dfs(int now){
	if(now == 4001){
		return true;
	}
	node_id[now].visited = v_flag;
	for(auto& ii : node_id[now].to_node){
		if(node_id[ii.first].visited!=v_flag && edge_id[ii.second].res>0){
			if(dfs(ii.first)){
				edge_id[ii.second].res--;
				edge_id[ii.second^1].res++;
				return true;
			}
		}
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, m, k, a, b, x, y;
	cin >> n >> m >> k;
	for(int i=0; i<=4001; i++){
		node_id[i].visited = 0;
	}
	for(int i=1; i<=n; i++){
		cin >> a;
		node_id[0].to_node.push_back({i, edge_id.size()});
		edge_id.push_back(Edge(a, a));
		edge_id.push_back(Edge(a, a));
	}
	for(int i=1; i<=m; i++){
		cin >> b;
		node_id[2000+i].to_node.push_back({4001, edge_id.size()});
		edge_id.push_back(Edge(b, b));
		edge_id.push_back(Edge(b, b));
	}
	for(int i=0; i<k; i++){
		cin >> x >> y;
		node_id[x].to_node.push_back({2000+y, edge_id.size()});
		edge_id.push_back(Edge(1, 1));
		node_id[2000+y].to_node.push_back({x, edge_id.size()});
		edge_id.push_back(Edge(1, 0));
	}
	
	while(dfs(0)){
		v_flag++;
	}
	cout << v_flag-1;
	return 0;
}
