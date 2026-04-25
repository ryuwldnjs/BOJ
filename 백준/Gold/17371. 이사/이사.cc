#include <iostream>
#include <algorithm>
using namespace std;
int n;
pair<int, int> map[1000+5]; 
int ans;

int dist(pair<int, int> a, pair<int, int> b){
	int x = a.first - b.first;
	int y = a.second - b.second;
	return x*x+y*y;
}


int main(){
//	cin.tie(NULL);
//	ios::sync_with_stdio(false);
	cin>>n;
	
	for(int i=0;i<n;i++){
		//cin>>map[i].first>>map[i].second;
		scanf("%d %d", &map[i].first, &map[i].second);
	}
	
	int idx=0,tmp=1000000000;
	for(int i=0;i<n;i++){
		ans=-1;
		for(int j=0;j<n;j++){
			if(i==j) continue;
			ans = max(ans, dist(map[i], map[j]));
		}
		
		if(tmp>ans){
			tmp=ans;
			idx=i;
		}
	}
	
	printf("%lf %lf", (double)map[idx].first, (double)map[idx].second);
	//cout<<(double)map[idx].first<<" "<<(double)map[idx].second;
	return 0;
}