#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int a[105], b[105], c[105];
vector<vector<int>> graph;
int MAX = -1;
vector<int> answer;

void dfs(int now, int cost, vector<int> &path){
    path.push_back(now);
    cost += b[now];
    if(MAX < cost){
        MAX = cost;
        answer = path;
    }

    for(int next : graph[now]){
        dfs(next, cost, path);
    }
    path.pop_back();
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    graph.resize(n+1);

    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i] < a[j] && c[i] < c[j]) graph[i].push_back(j);
        }
    }

    //i번 노드 스타트
    for(int i=1;i<=n;i++){
        vector<int> path;
        dfs(i, 0, path);
    }

    cout<<answer.size()<<'\n';
    for(int i : answer) cout<<i<<'\n';
    return 0;
}