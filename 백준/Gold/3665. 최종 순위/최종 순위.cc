#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int T, n, arr[505], m, a,b;
int main(){
	cin>>T;
	while(T--){
		vector<vector<int> > vec;
		int indegree[505]={};
		cin>>n;
		vec.resize(n+1);
		
		for(int i=1;i<=n;i++){
			cin>>arr[i];
			for(int j=1;j<i;j++){
				vec[arr[j]].push_back(arr[i]);
				indegree[arr[i]]++;
			}
		}
		
		cin>>m;
		for(int i=0;i<m;i++){
			cin>>a>>b;
			int flag=0;
			
			for(int j=0;j<vec[a].size();j++){
				if(vec[a][j]==b){
					flag=1;
					vec[a].erase(vec[a].begin()+j);
					vec[b].push_back(a);
					indegree[b]--;
					indegree[a]++;
					break;
				}
			}
			
			if(flag!=1)
			for(int j=0;j<vec[b].size();j++){
				if(vec[b][j]==a){
					flag=2;
					vec[b].erase(vec[b].begin()+j);
					vec[a].push_back(b);
					indegree[a]--;
					indegree[b]++;
					break;
				}
			}
			
			
			
		}
		
		int prev, error=0;
		vector<int> answer;
		for(int i=0;i<n;i++){
			int flag=0;
			for(int j=1;j<=n;j++){
				if(indegree[j]==i){
					flag=1;
					answer.push_back(j);
				}
				
			}
			if(flag==0){//i번째가 안쓰였다고.,.?
				error=1; 
			}
		}
		
		
		if(answer.size()==n){
			if(error){
			cout<<"IMPOSSIBLE\n";
			continue;
		}
			for(int i=0;i<answer.size();i++) cout<<answer[i]<<' ';
		}
		else
			cout<<"IMPOSSIBLE";
		cout<<'\n';
	}	
	return 0;
}