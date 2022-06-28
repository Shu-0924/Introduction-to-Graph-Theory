#include<iostream>
#include<vector>
using namespace std;

int bridge;
vector<int> depth;
vector<vector<int>> edge;

int dfs(int now, int parent){
	if(depth[now]!=-1){
		return depth[now];
	}
	depth[now] = depth[parent]+1;
	
	int back_depth = depth[now]+1;
	for(int& child: edge[now]){
		if(child==parent){
			continue;
		}
		int child_back_depth = dfs(child, now);
		if(child_back_depth <= depth[now]){
			bridge--;
		}
		back_depth = min(back_depth, child_back_depth);
	}
	return back_depth;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, m, x, y;
	cin >> n >> m;
	edge.resize(n+1);
	depth.resize(n+1, -1);
	for(int i=0; i<m; i++){
		cin >> x >> y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	
	bridge = m;
	dfs(1, 1);
	cout << bridge;
	return 0;
}
