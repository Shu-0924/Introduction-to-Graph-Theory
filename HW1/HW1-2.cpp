#include<iostream>
#include<queue>
using namespace std;

struct Node{
	int color;
	vector<int> to_node;
} node_id[200005];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, m, a, b;
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		node_id[i].color = 0;
	}
	for(int i=0; i<m; i++){
		cin >> a >> b;
		node_id[a].to_node.push_back(b);
		node_id[b].to_node.push_back(a);
	}
	
	node_id[1].color = 1;
	queue<int> Q;
	Q.push(1);
	while(!Q.empty()){
		int now = Q.front();
		Q.pop();
		for(int& next: node_id[now].to_node){
			if(node_id[next].color == node_id[now].color){
				cout << -1;
				exit(0);
			}
			if(node_id[next].color == 0){
				node_id[next].color = -node_id[now].color;
				Q.push(next);
			}
		}
	}
	
	int cnt = 0;
	for(int i=1; i<=n; i++){
		cnt += (node_id[i].color == 1);
	}
	cout << cnt << ' ' << n-cnt;
	return 0;
}
