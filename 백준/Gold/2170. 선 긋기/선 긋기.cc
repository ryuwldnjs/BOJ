#include <bits/stdc++.h>
using namespace std;
using pll=pair<long, long>; 
long long n,x,y;
vector<pll> line;
long long answer, last = -1e9;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		line.push_back({x,y});
	}
	sort(line.begin(), line.end());
	
	
	for(int i=0;i<n;i++){
		//완전히 포함
//		if(line[i].second <= last) continue;
		//반쯤 걸쳐있을때 
		if(line[i].first <= last&&last <= line[i].second){
			answer += line[i].second - last;
			last = line[i].second;
		}
		//안겹칠때 
		else if(last < line[i].first){
			answer += line[i].second - line[i].first;
			last = line[i].second;
		}
	}
	
	cout<<answer;
	return 0;
}