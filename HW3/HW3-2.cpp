#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n;
int parent[200005];
vector<pair<pair<int, bool>, pair<int, int>>> edge;


int get_root(int a) {
    if (parent[a] < 0) {
        return a;
    }
    return parent[a] = get_root(parent[a]);
}

bool join(int a, int b) {
    int root_a = get_root(a);
    int root_b = get_root(b);
    if (root_a != root_b) {
        if (parent[root_a] <= parent[root_b]) {
            parent[root_a] += parent[root_b];
            parent[root_b] = root_a;
        }
        else {
            parent[root_b] += parent[root_a];
            parent[root_a] = root_b;
        }
        return true;
    }
    return false;
}

long long compute_mst(){
	for(int i=1; i<=n; i++){
		parent[i] = -1;
	}
	sort(edge.begin(), edge.end());
	
	long long ret = 0;
	for(int i=0, cnt=0; cnt<n-1; i++){
		if(join(edge[i].second.first, edge[i].second.second)){
			edge[i].first.second = true;
			ret += edge[i].first.first;
			cnt++;
		}
	}
	return ret;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int m, x, y, w;
	cin >> n >> m;
	for(int i=0; i<m; i++){
		cin >> x >> y >> w;
		edge.push_back({{w, false}, {x, y}});
	}
	
	long long mst = compute_mst();
	cout << mst << '\n';
	
	compute_mst();
	int cnt = 0;
	for(int i=0; i<edge.size(); i++){
		cnt += edge[i].first.second;
	}
	cout << (cnt==n-1? "YES": "NO");
	return 0;
}
