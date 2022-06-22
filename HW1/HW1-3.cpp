#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int n, d;
int D[200005] = {};

// single point query
int query(int x){
	int ret = 0;
	while(x){
		ret += D[x];
		x -= x&(-x);
	}
	return ret;
}

// postfix update
void update(int x, int d){
	while(x <= n){
		D[x] += d;
		x += x&(-x);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> n;
	vector<int> seq;
	seq.push_back(0);
	for(int i=0; i<n; i++){
		cin >> d;
		seq.push_back(d);
	}
	sort(seq.begin(), seq.end());	
	for(int i=1; i<seq.size(); i++){
		update(i, seq[i]-seq[i-1]);
	}
	
	int last = n;
	while((d = query(last))!=0){
		if(d>last){
			cout << "No";
			exit(0);
		}
		int target_num = query(last-d);
		if(target_num == 0){
			cout << "No";
			exit(0);
		}
		int upper_index = last, step=1<<18;
		while(step){
			if(upper_index-step>0 && query(upper_index-step)>target_num){
				upper_index -= step;
			}
			step >>= 1;
		}
		int lower_index = last;
		step=1<<18;
		while(step){
			if(lower_index-step>0 && query(lower_index-step)>=target_num){
				lower_index -= step;
			}
			step >>= 1;
		}
		update(upper_index, -1);
		update(lower_index, -1);
		update(lower_index+(d-(last-upper_index)), 1);
		last--;
	}
	cout << "Yes";
	return 0;
}
