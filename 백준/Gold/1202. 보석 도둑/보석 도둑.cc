#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
vector<int> parent(300000+5, -1), pocket;
vector<pii> gems;
long long answer;
int n,k;
int find(int x){
	if(parent[x] < 0) return x;
	return parent[x] = find(parent[x]);
}
int main(){
	cin>>n>>k;
	for(int i=0;i<n;i++) {
		int m,v;
		cin>>m>>v;
		gems.push_back({v,m}); //가치, 무게 
	}
	for(int i=0;i<k;i++){
		int c;
		cin>>c;
		pocket.push_back(c);
	}
	sort(gems.begin(), gems.end(), greater<pii>());
	sort(pocket.begin(), pocket.end());
	
	for(auto gem : gems){
		int v = gem.first;
		int m = gem.second;
		int target = lower_bound(pocket.begin(), pocket.end(), m) - pocket.begin();
		target = find(target);
		
		if(target < k){
			answer += (long long) v;
			parent[target] = target + 1;
		}
	}
	cout<<answer;
	return 0;
}