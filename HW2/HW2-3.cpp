#include<iostream>
#define INF 1000000007
using namespace std;

int n;
int color[21];
int dist[21][21];
int path[21][21];
int dp[1<<21][21] = {};
int complete_bitmask;


int TSP(int bitmask, int now){
	if(dp[bitmask][now]!=0){
		return dp[bitmask][now];
	}
	if(bitmask==complete_bitmask){
		return dp[bitmask][now] = 0;
	}
	
	int best = INF;
	for(int next=1; next<=n; next++){
		if(!(bitmask&(1<<color[next]))){ // not collected
			best = min(best, dist[now][next] + TSP(bitmask|path[now][next], next));
		}
	}
	return dp[bitmask][now] = best;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int m, k, x, y, w;
	cin >> n >> m >> k;
	for(int i=1; i<=n; i++){
		cin >> color[i];
	}
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			dist[i][j] = INF;
			path[i][j] = (1<<color[i])|(1<<color[j]);
		}
		dist[i][i] = 0;
		dist[0][i] = 0;
	}
	for(int i=0; i<m; i++){
		cin >> x >> y >> w;
		dist[x][y] = w;
		dist[y][x] = w;
	}
	
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(dist[i][k] + dist[k][j] < dist[i][j]){
					dist[i][j] = dist[i][k] + dist[k][j];
					path[i][j] = path[i][k] | path[k][j];
				}
			}
		}
	}
	
	complete_bitmask = (1<<(k+1))-1;
	cout << TSP(1, 0);
	return 0;
}
