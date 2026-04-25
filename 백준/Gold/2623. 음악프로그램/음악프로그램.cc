#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int> > vec;
vector<int> answer;
queue<int> q;
int indegree[1005];

int n,m, k, arr[1005];
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n>>m;
	vec.resize(n+1);
	
	for(int i=0;i<m;i++){
		cin>>k;
		for(int j=0;j<k;j++){
			cin>>arr[j];
			if(j){
				vec[arr[j-1]].push_back(arr[j]);
				indegree[arr[j]]++;
			}
		}
	}
	//위상정렬을 위한 그래프 구성
	
	 
	for(int i=1;i<=n;i++){
		if(!indegree[i]) q.push(i);//indegree가 0인 정점부터 push 
	}
	
	
	while(!q.empty()){
		int now = q.front();
		q.pop();
		answer.push_back(now);
		
		for(int i=0;i<vec[now].size();i++){
			int next = vec[now][i];
			indegree[next]--;
			if(indegree[next]==0) q.push(next);
		}
	}
	//위상정렬
	if(answer.size()!=n) cout<<0;
	else for(int i=0;i<answer.size();i++) cout<<answer[i]<<'\n';
	return 0;
}