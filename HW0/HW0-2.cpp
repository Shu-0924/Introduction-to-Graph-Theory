#include<iostream>
using namespace std;

int h[100005] = {};

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int n, a;
	cin >> n;
	for(int i=1; i<=n; i++){
		cin >> a;
		h[a]++;
	}
	int ans = 0;
	for(int i=1; i<=n; i++){
		if(h[i] >= h[ans]){
			ans = i;
		}
	}
	cout << ans << ' ' << h[ans] << '\n';
	return 0;
}
