#include<iostream>
#include<vector>
#define ll long long
using namespace std;

struct Node{
	int color;
	int level;
	vector<int> to_node;
} node_id[25];

void explore(int now, int d){
	node_id[now].level = d;
	for(int& next: node_id[now].to_node){
		if(node_id[next].level == -1){
			explore(next, d+1);
		}
	}
}

ll dfs_count(int now, int c){
	for(int& x: node_id[now].to_node){
		if(node_id[x].color == c){
			return 0;
		}
	}
	
	ll ret = 1;
	node_id[now].color = c;
	for(int& x: node_id[now].to_node){
		if(node_id[x].level == node_id[now].level+1){
			ll temp = 0;
			for(int i=1; i<=3; i++){
				temp += dfs_count(x, i);
			}
			ret *= temp;
		}
	}
	node_id[now].color = 0;
	return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, m, x, y;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		node_id[i].color = 0;
		node_id[i].level = -1;
	}
	for(int i=0; i<m; i++){
		cin >> x >> y;
		node_id[x].to_node.push_back(y);
		node_id[y].to_node.push_back(x);
	} 
	
	for(int i=1; i<=n; i++){
		if(node_id[i].level == -1){
			explore(i, 1);
		}
	}
	ll ans = 1;
	for(int i=1; i<=n; i++){
		if(node_id[i].level == 1){
			ans *= dfs_count(i, 1) * 3;
		}
	}
	cout << ans;
	return 0;
} 
