#include <iostream>
#include <vector>
#define INF 1234567890
using namespace std;

int visited[10000+5];
vector<vector<int> > arr;
vector<int> a;
int n,m,k,x,y,sum;
int dfs(int now){
	visited[now] = 1;
	int MIN = a[now];
		
	for(int i=0;i<arr[now].size();i++){
		int next = arr[now][i];
		if(!visited[next]) MIN = min(MIN, dfs(next));
	}
	
	return MIN;
}

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin>>n>>m>>k;
	a.resize(n+1), arr.resize(n+1);
	for(int i=1;i<=n;i++) cin>>a[i];
	
	for(int i=0;i<m;i++){
		cin>>x>>y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			sum += dfs(i);
		}
	}
	
	if(sum<=k) cout<<sum;
	else cout<<"Oh no";
	return 0;
}