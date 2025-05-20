#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int id;
vector<int> d, SCCid, cash, SCCcash;
vector<bool> finished;
vector<vector<int>> graph, SCC;
stack<int> s;

//타잔
int dfs(int now){
    d[now] = id++;
    s.push(now);
    int parent = d[now];
    for(int next: graph[now]){
        if(d[next] == -1) parent = min(parent, dfs(next));
        else if(!finished[next]) parent = min(parent, d[next]);
    }

    if(parent == d[now]){
        vector<int> scc;
        int cash_sum = 0;
            while(true){
                int top = s.top();
                s.pop();

                scc.push_back(top);
                finished[top] = true;
                SCCid[top] = SCC.size();
                cash_sum += cash[top];
                if(top == now) break;
            }
            SCC.push_back(scc);
            SCCcash.push_back(cash_sum);
    }
    
    return parent;
}



vector<vector<int>> SCCgraph;//SCC로 만든 새로운 그래프
vector<int> dist;
void solve(int now, int distance){
    dist[now] = max(dist[now], distance + SCCcash[now]);
    for(int next: SCCgraph[now]){
        if(dist[next] >= dist[now] + SCCcash[next]) continue;
        solve(next, dist[now]);
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m; cin>>n>>m;
    graph.resize(n+1);
    d.resize(n+1, -1);
    SCCid.resize(n+1);
    finished.resize(n+1, false);
    cash.resize(n+1);

    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        graph[a].push_back(b);
    }
    for(int i=1;i<=n;i++){
        cin>>cash[i];
    }
    int start,p;
    cin>>start>>p;
    vector<int> dest(p);
    for(int i=0;i<p;i++){
        cin>>dest[i];
    }
    for(int i=1;i<=n;i++){
        if(d[i] == -1) dfs(i);
    }
    //여기까지 SCC
    SCCgraph.resize(SCC.size());
    dist.resize(SCC.size());

    for(int i=0;i<graph.size();i++){
        for(int j=0;j<graph[i].size();j++){
            int next = graph[i][j];
            if(SCCid[i] != SCCid[next]){
                SCCgraph[SCCid[i]].push_back(SCCid[next]);
            }
        }
    }

    //SCC그래프에 맞게 인덱스 재조정
    start = SCCid[start];
    for(int i=0;i<p;i++){
        dest[i] = SCCid[dest[i]];
    }
    solve(start, 0);

    int answer = 0;
    for(int i=0;i<p;i++){
        int target = dest[i];
        answer = max(answer, dist[target]);
    }
    cout<<answer;
    return 0;
}