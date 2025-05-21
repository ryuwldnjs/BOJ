#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<vector<int>> graph;
vector<int> l,r;
vector<bool> visited;
bool dfs(int x){
    if(visited[x]) return false;
    visited[x] = true;
    for(int y: graph[x]){
        if(r[y] == -1 || dfs(r[y])){
            r[y] = x;
            l[x] = y;
            return true;
        } 
    }
    return false;
}

void solve(){
    int c,d,v;cin>>c>>d>>v;
    l = vector<int>(v, -1);
    r = vector<int>(v, -1);
    graph = vector<vector<int>>(v);
    vector<pair<string,string>> votes(v);

    for(int i=0;i<v;i++){
        string a,b;cin>>a>>b;
        votes[i] = {a,b};
    }
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(votes[i].first[0] != 'C') continue; //왼쪽은 고양이
            if(votes[i].second == votes[j].first || votes[i].first == votes[j].second){
                graph[i].push_back(j);
            }
        }
    }


    //최소컷
    int answer = v;
    for(int i=0;i<v;i++){
        if(votes[i].first[0] != 'C') continue;
        visited = vector<bool>(v);
        if(dfs(i)) answer--; 
    }
    cout<<answer<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}