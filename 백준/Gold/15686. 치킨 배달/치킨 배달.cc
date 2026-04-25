#include <iostream>
#include <vector>
using namespace std;
using pii=pair<int,int>;
vector<pii> home, chicken, list;
int MIN = 1e9;
int n,m,x;
void solve(int num){
	if(list.size() == m){
		int sum = 0;
		for(int i=0;i<home.size();i++){
			int chicken_dist = 1e9;
			for(int j=0;j<list.size();j++){
				int dist = abs(home[i].first - list[j].first) + abs(home[i].second - list[j].second);
				chicken_dist = min(chicken_dist, dist);
			}
			sum += chicken_dist;
		}
		MIN = min(MIN, sum);
		return;
	}
	//중간 최적화
	if(list.size() + chicken.size()-num < m){
		return;
	}
	
	list.push_back(chicken[num]);
	solve(num+1);
	list.pop_back();
	solve(num+1);
}

int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			pii pos = {i,j};
			cin>>x;
			if(x == 1) home.push_back(pos);
			else if(x == 2) chicken.push_back(pos);
		}
	}
	
	solve(0);
	cout<<MIN;
	return 0;
}