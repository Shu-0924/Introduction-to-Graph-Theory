#include <iostream>
using namespace std;

bool adj_matrix[20][20] = {};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, m, x, y;
	cin >> n >> m;
	for(int i=0; i<m; i++) {
		cin >> x >> y;
		adj_matrix[x][y] = 1;
		adj_matrix[y][x] = 1;
	}
	bool K5 = false;
	if(n >= 5) {
		for(int a=1; a<=n; a++) {
			for(int b=a+1; b<=n; b++) {
				for(int c=b+1; c<=n; c++) {
					for(int d=c+1; d<=n; d++) {
						for(int e= d+1; e<=n; e++) {
							if(adj_matrix[a][b] && adj_matrix[a][c] && adj_matrix[a][d] && adj_matrix[a][e]) {
								if(adj_matrix[b][c] && adj_matrix[b][d] && adj_matrix[b][e]) {
									if(adj_matrix[c][d] && adj_matrix[c][e]) {
										if(adj_matrix[d][e]) {
											K5 = true;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
	
	bool K33 = false;
	int triple[10000][3], size = 0;
	if (n >= 6) {
		for (int a=1; a<=n; a++) {
			for (int b=a+1; b<=n; b++) {
				for (int c=b+1; c<=n; c++) {
					triple[size][0] = a;
					triple[size][1] = b;
					triple[size++][2] = c;
				}
			}
		}
		for (int i=0; i<size; i++) {
			for (int j=i+1; j<size; j++) {
				bool flag = true;
				for (int a=0; a<3; a++) {
					for (int b=0; b<3; b++) {
						if (!adj_matrix[triple[i][a]][triple[j][b]]) {
							flag = false;
						}
					}
				}
				if (flag == true) {
					K33 = true;
					break;
				}
			}
		}
	}
	
	cout << (int)K5*2+(int)K33;
	return 0;
}
