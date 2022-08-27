#include<iostream>
#include<vector>
using namespace std;

struct Node{
	int visited;
	vector<pair<int, int>> to_node;
} node_id[4005];
vector<int> res;


int v_flag = 1;
bool dfs(int now){
	if(now == 4001){
		return true;
	}
	node_id[now].visited = v_flag;
	for(auto& ii : node_id[now].to_node){
		if(node_id[ii.first].visited!=v_flag && res[ii.second]>0){
			if(dfs(ii.first)){
				res[ii.second]--;
				res[ii.second^1]++;
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
		node_id[0].to_node.push_back({i, res.size()});
		res.push_back(a);
		res.push_back(a);
	}
	for(int i=1; i<=m; i++){
		cin >> b;
		node_id[2000+i].to_node.push_back({4001, res.size()});
		res.push_back(b);
		res.push_back(b);
	}
	for(int i=0; i<k; i++){
		cin >> x >> y;
		node_id[x].to_node.push_back({2000+y, res.size()});
		res.push_back(1);
		node_id[2000+y].to_node.push_back({x, res.size()});
		res.push_back(0);
	}
	
	while(dfs(0)){
		v_flag++;
	}
	cout << v_flag-1;
	return 0;
}
