#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<int> parent;
struct DSU{
    vector<int> parent;
    vector<set<int>> color;
    DSU(int n) : parent(n+1, -1), color(n+1) {}

    int find(int x){
        if(parent[x] < 0) return x;
        return parent[x] = find(parent[x]);
    }
    int merge(int a, int b){
        a = find(a);
        b = find(b);
        if(a == b) return 0;

        parent[a] += parent[b];
        parent[b] = a;
        
        if(color[a].size() < color[b].size()) swap(color[a], color[b]);
        color[a].insert(color[b].begin(), color[b].end());
        color[b].clear();
        return 1;
    }
    int getColors(int x){
        x = find(x);
        return color[x].size();
    }

};
DSU dsu(100000+5);
vector<pii> query;
vector<int> answer;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,q;cin>>n>>q;
    parent.resize(n+1,-1);
    query.resize(n+q-1);
    for(int i=2;i<=n;i++){
        cin>>parent[i];
    }
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        dsu.color[i].insert(x);
    }
    for(int i=0;i<n+q-1;i++){
        cin>>query[i].first>>query[i].second;
    }


    //Offline
    reverse(query.begin(), query.end());

    for(auto [a,b] : query){
        if(a == 1) dsu.merge(parent[b], b);
        else answer.push_back(dsu.getColors(b));   
    }

    reverse(answer.begin(), answer.end());
    for(int i:answer) cout<<i<<'\n';

    return 0;
}