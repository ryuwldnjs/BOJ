#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int w[1005], num, a,b, n,k,T;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>T;
	while(T--){
		vector<vector<int> > vec, in;
		queue<int> q;
		int indegree[1005]={};
		cin>>n>>k;
		
		vec.resize(n+1), in.resize(n+1);
		for(int i=1;i<=n;i++) cin>>w[i];
		
		for(int i=0;i<k;i++){
			cin>>a>>b;
			vec[a].push_back(b);
			indegree[b]++;
		}
		cin>>num; //찾아야 할 번호
		//여기까지 위상정렬 그래프 생성
		
		
		
		for(int i=1; i<=n;i++){
			if(!indegree[i]) {//들어오는 간선이 없으면 push 
				q.push(i);
			}
		} 
		
		while(!q.empty()){
			int now = q.front();
			q.pop();
			
			int MAX = 0;
			for(int i=0;i<in[now].size();i++)
				MAX = max(MAX, in[now][i]); //들어오는 간선중 가장 긴거 찾기 
			w[now] += MAX;//가중치에 합해주기 
			
			if(now==num) break;//찾고싶은 정점을 발견
			 
			
			
			for(int i=0;i<vec[now].size();i++){
				int next = vec[now][i];
				indegree[next]--;
				
				in[next].push_back(w[now]);//다음 정점에 현 가중치를 보내줌
				
				if(indegree[next]==0)	q.push(next);
				
			}
		}
		
		cout<<w[num]<<'\n';		
	}
	return 0;
}