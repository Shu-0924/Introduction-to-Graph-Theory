#include<iostream>
#include<set>
using namespace std;


multiset<int> S;
int score[2005] = {};
int result[2005][2005];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, k, a, b, c, r;
	cin >> n >> k >> a >> b >> c;
	int p[3] = {b, a, c};
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			cin >> result[i][j];
			score[i] += p[result[i][j]];
		}
		S.insert(score[i]);
	}
	
	int counter[3] = {1, 0, 2};
	for(int i=0; i<k; i++){
		cin >> r >> c >> a;
		S.erase(S.find(score[r]));
		S.erase(S.find(score[c]));
		score[r] -= p[result[r][c]];
		score[c] -= p[result[c][r]];
		result[r][c] = a;
		result[c][r] = counter[a];
		score[r] += p[result[r][c]];
		score[c] += p[result[c][r]];
		S.insert(score[r]);
		S.insert(score[c]);
		cout << *S.rbegin()-*S.begin() << ' ';
	}
	return 0;
}
