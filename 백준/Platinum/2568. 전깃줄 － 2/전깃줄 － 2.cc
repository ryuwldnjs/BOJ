#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
int n,a,b;
vector<pii> line;
vector<int> lis, corr;
stack<int> answer; 
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		line.push_back({a,b});
	}
	sort(line.begin(), line.end());
	
	for(int i=0;i<line.size();i++){
//		printf("%d ",i);
		int target = lower_bound(lis.begin(), lis.end(), line[i].second) - lis.begin();
		if(target == lis.size()) lis.push_back(line[i].second);
		else lis[target] = line[i].second;
		corr.push_back(target);
	}
	
	int idx = lis.size()-1;
	for(int i=n-1;i>=0;i--){
		if(idx == corr[i]){
			idx--;
			answer.push(i);
		}
	}
	
	cout<<n - answer.size()<<'\n';
	for(int i=0;i<n;i++){
		if(answer.empty() || i != answer.top()){
			cout<<line[i].first<<'\n';
		}
		else answer.pop();
	}
	return 0;
}