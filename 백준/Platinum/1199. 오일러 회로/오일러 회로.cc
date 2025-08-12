#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n;
int graph[1005][1005];
int degree[1005];
vector<int> answer;

void dfs(int now){
    for(int next=1;next<=n && degree[now]; next++){
        while(graph[now][next] > 0){
            graph[now][next]--;
            graph[next][now]--;
            degree[now]--;
            degree[next]--;
            dfs(next);
        }
    }

    answer.push_back(now);
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>graph[i][j];
            degree[i]+= graph[i][j];
        }
    }

    dfs(1);

    if(answer.front() != answer.back()){
        cout<<-1;
        return 0;
    }

    for(int i:answer) cout<<i<<' ';
    return 0;
}