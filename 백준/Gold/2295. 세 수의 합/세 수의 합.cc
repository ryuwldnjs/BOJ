#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
using pii=pair<int,int>;
map<int, pii> m;
vector<int> vec;
int n,c,MAX=-1;
int main(){
	cin>>n;
	vec.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>c;
		vec[i] = c;
	}
	sort(vec.begin()+1, vec.end());
	
	for(int i=1;i<=n;i++){
		for(int j=i; j<=n;j++){
			int sum = vec[i] + vec[j];
			if(m[sum].second == 0) m[sum] = {i,j};
			if(m[sum].second > j){
				m[sum] = {i,j}; 
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			//sum + vec[i] = vec[j]
			//sum = vec[j] - vec[i]
			int sub = vec[j] - vec[i];
			if(m[sub].second > 0 && m[sub].second <= i)
				MAX = max(MAX, vec[j]);
		}
	}
	cout<<MAX;
	return 0;
}