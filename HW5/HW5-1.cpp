#include<iostream>
#define INF 1000000007
using namespace std;

int adj[502][502];
int cost[502][502];

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, m, directed, x, y, w;
    cin >> n >> m >> directed;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cost[i][j] = adj[i][j] = INF;
        }
        cost[i][i] = adj[i][i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> w;
        cost[x][y] = adj[x][y] = w;
        if (!directed) {
            cost[y][x] = adj[y][x] = w;
        }
    }
    
    int ans = INF;
    for (int k = 1; k <= n; k++) {
        if (!directed) {
            for (int i = 1; i <= k - 1; i++) {
                for (int j = i + 1; j <= k - 1; j++) {
                    ans = min(ans, cost[i][j] + adj[j][k] + adj[k][i]);
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }
    
    if (directed) {
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans = min(ans, cost[i][j] + cost[j][i]);
            }
        }
    }
    cout << (ans==INF?-1:ans);
	return 0;
}
