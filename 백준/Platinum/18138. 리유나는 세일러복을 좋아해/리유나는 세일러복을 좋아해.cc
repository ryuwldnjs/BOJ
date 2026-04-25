#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > adj;
vector<int> shirt, match;
bool visited[205];
int n,m,k,cnt;
//세일러 카라를 붙일수 있는지 확인 
bool judge(int a, int b){
	double w = (double) a;
	double k = (double) b;
	
	if(w/2. <= k&&k <= w*3./4. || w<=k&&k<=w*5./4.)
		return true;
	return false;
}

//이분 매칭 
bool DFS(int a){
	if(visited[a]) return false;
	visited[a] = true;
	
	for(int i=0;i<adj[a].size();i++){
		int b = adj[a][i];
		
		if(match[b] == -1 || DFS(match[b])){
			match[b] = a;
			return true;
		}
	}
	
	return false;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	adj.resize(n+1), match.resize(m+1, -1);
	shirt.resize(n+1);
	for(int i=1;i<=n;i++) cin>>shirt[i];
	
	for(int i=1;i<=m;i++){//카라
		cin>>k;
		
		for(int j=1;j<=n;j++){//셔츠
			int &w = shirt[j];
			
			if(judge(w, k))
				adj[j].push_back(i);
		}
	}
	//이분그래프 완성
	
	 
	for(int i=1;i<=n;i++){
		fill(visited, visited+n+1, false);
		if(DFS(i)) cnt++;
	} 
	
	cout<<cnt;
	return 0;
}