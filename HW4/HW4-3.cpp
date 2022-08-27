#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
#define ll long long
using namespace std;

struct Edge{
	int u;
	int v;
	int w;
};
vector<Edge> edge_id;
long long node_dp[200005] = {};

bool cmp(Edge& a, Edge& b){
	return a.w < b.w;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n;
	cin >> n;
	for(int i=0; i<n-1; i++){
		Edge e;
		cin >> e.u >> e.v >> e.w;
		edge_id.push_back(e);
	}
	sort(edge_id.begin(), edge_id.end(), cmp);
	
	unordered_map<int, ll> temp;
	int last_w = edge_id[0].w;
	for(Edge& e: edge_id){
		if(e.w != last_w){
			for(auto& x:temp){
				node_dp[x.first] += x.second;
			}
			temp.clear();
		}
		temp[e.v] += node_dp[e.u] + 1;
		temp[e.u] += node_dp[e.v] + 1;
		last_w = e.w;
	}
	for(auto& x:temp){
		node_dp[x.first] += x.second;
	}
	
	ll ans = 0;
	for(int i=1; i<=n; i++){
		ans += node_dp[i];
	}
	cout << ans;
	return 0;
} 
