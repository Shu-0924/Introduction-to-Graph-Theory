#include<iostream>
using namespace std;

int score[2005] = {};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, a, b, c, result;
	cin >> n >> a >> b >> c;
	int p[3] = {b, a, c};
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> result;
			if(i == j){
				continue;
			}
			score[i] += p[result];
		}
	}
	
	
	for(int i=0; i<n; i++){
		cout << score[i] << ' ';
	}
	return 0;
}
