#include <iostream>
#include <vector>
#include <queue>
using namespace std;

queue<int> q;
vector<pair<int,int> > path;
vector<char> ans;
int T,a,b;
int main(){
	cin>>T;
	
	while(T--){
		cin>>a>>b;
		
		q = queue<int>();
		path = vector<pair<int,int> >(10000);
		ans = vector<char>();
		
		
		q.push(a);
		path[a] = {a, 'X'};
		//path[a].push_back('X');
		
		while(!q.empty()){
			int now = q.front();
			q.pop();
			if(now == b) break;
			
			int D = now*2 % 10000;
			int S = (now+9999) % 10000;
			int L = (now*10)%10000 + now/1000;
			int R = now/10 + (now%10) * 1000;
		//	printf("%d : %d %d %d %d\n", now, D,S,L,R);
		//	for(int i=0;i<path[now].size();i++) printf("%c ", path[now][i]);
		//	printf("\n");
	
		//각 명령어별로 방문하지 않은 곳일 경우, 명령어 이어 붙이기 
			if(!path[D].second){
				q.push(D);
				path[D] = {now, 'D'};
			}
			if(!path[S].second){
				q.push(S);
				path[S] = {now, 'S'};
			}
			if(!path[L].second){
				q.push(L);
				path[L] = {now, 'L'};
			}
			if(!path[R].second){
				q.push(R);
				path[R] = {now, 'R'};
			}
		}
	//	printf("Zz");
		
		
		while(a != b){
		//	printf("%d,%c\n", path[b].first,path[b].second);
			ans.push_back(path[b].second);
			b = path[b].first;
		}
		int sz = ans.size();
		for(int i=sz-1; i>=0; i--){
			cout<<ans[i];
		}
		cout<<'\n';
	}
	return 0;
} 