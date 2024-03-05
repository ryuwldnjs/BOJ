#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
int n, W[15][15];
int MIN = INF;
int main(){
	cin>>n;
	vector<int> order(n);
	for(int i=0;i<n;i++) order[i]=i;
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>W[i][j];
			if(W[i][j]==0) W[i][j] = INF;
		}
	}
	
	do{
		int cost = 0;
		for(int i=0;i<n-1;i++){
			int from = order[i];
			int to = order[i+1];
			cost += W[from][to];
		}
		cost += W[order[n-1]][order[0]];
		MIN = min(MIN, cost);
	}while(next_permutation(order.begin(), order.end()));
	
	cout<<MIN;
	return 0;
}