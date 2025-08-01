#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Edge{
    int a,b;
    int cost;
};

struct DSU{
    vector<int> parent;
    DSU(int n){
        parent.resize(n, -1);
    } 

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
        return 1;
    }
};

vector<Edge> edges;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<m+1;i++){
        int a,b,c;cin>>a>>b>>c;
        edges.push_back({a,b,1-c});
    }


    int MIN=0,MAX=0;
    DSU dsu(n+1);
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.cost < b.cost;
    });
    for(Edge e: edges){
        if(dsu.merge(e.a, e.b)) MIN += e.cost;
    }


    DSU dsu2(n+1);
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){
        return a.cost > b.cost;
    });
    for(Edge e: edges){
        if(dsu2.merge(e.a, e.b)) MAX += e.cost;
    }

    // printf("%d %d\n", MAX, MIN);

    cout<<MAX*MAX - MIN*MIN;
    return 0;
}