#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii=pair<int,int>;
vector<vector<int>> graph;
vector<int> discovered;
vector<pii> ans;
int v,e, cnt;
int dfs(int now, int parent){
    discovered[now] = ++cnt;
    int num = discovered[now];

    for(int i=0;i<graph[now].size();i++){
        int next = graph[now][i];
        if(next == parent) continue; //직속 부모는 생략: 방금 거쳐온 노드임

        if(discovered[next] == 0){
            int subtree = dfs(next, now);
            num = min(num, subtree);
            if(discovered[now] < subtree) ans.push_back({min(now, next), max(now, next)});
        }
        else{
            num = min(num, discovered[next]);
        }
    }
    return num;
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>v>>e;
    graph.resize(v+1);
    discovered.resize(v+1);
    for(int i=0;i<e;i++){
        int a,b; cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1, 0);
    sort(ans.begin(), ans.end());
    cout<<ans.size()<<'\n';
    for(auto p: ans){
        cout<<p.first<<' '<<p.second<<'\n';
    }
    return 0;
}