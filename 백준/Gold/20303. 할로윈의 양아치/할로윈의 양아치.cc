#include <iostream>
#include <vector>
using namespace std;
using pii=pair<int,int>;
vector<vector<int>> map;
vector<pii> group(1);//{사람수, 사탕수}

int n,m,k, a,b;
int candy[30000+5];
int dp[30000+5][3000+5];
bool visited[30000+5]; 
pii dfs(int now){
	pii result={1,candy[now]}; // {사람수, 사탕수}
	visited[now] = true;
	
	for(int i=0;i<map[now].size();i++){
		int next = map[now][i];
		if(!visited[next]){
			pii tmp = dfs(next);
			result.first += tmp.first;
			result.second += tmp.second;
		}
	}
	return result;
}
int main(){
	cin>>n>>m>>k;
	map.resize(n+1);
	for(int i=1;i<=n;i++){
		cin>>candy[i];
	}
	for(int i=0;i<m;i++){
		cin>>a>>b;
		map[a].push_back(b);
		map[b].push_back(a);
	}
	
	for(int i=1;i<=n;i++){
		if(!visited[i]){
			group.push_back(dfs(i));
		}
	}
	//여기까지 그루핑완료
	
//	for(int i=1;i<group.size();i++){
//		printf("%d : %d, %d\n", i, group[i].first, group[i].second);
//	}

	//냅색 문제 
	for(int i=1;i<group.size();i++){
		int weight = group[i].first;
		int value = group[i].second;
		for(int j=0;j<k;j++){ //weight 여기선 우는 아이 수 
			dp[i][j] = dp[i-1][j];
			
			if(j - weight >= 0){
				dp[i][j] = max(dp[i][j], dp[i-1][j - weight] + value);
			}
			
		}
	}
	
	cout<<dp[group.size()-1][k-1];
	return 0;
}