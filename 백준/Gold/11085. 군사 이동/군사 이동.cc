#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Edge{
    int a,b,cost;
    bool operator<(const Edge &other)const{
        return cost > other.cost;
    }
};

vector<int> parent(1005, -1);
int find(int x){
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

int merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a==b) return 0;

    parent[b] = a;
    return 1;
}

int p,w,c,v;
vector<Edge> edges;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>p>>w;
    cin>>c>>v;
    for(int i=0;i<w;i++){
        int a,b,c;cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }

    sort(edges.begin(), edges.end());

    for(auto [a,b,cost] : edges){
        merge(a,b);
        if(find(c) == find(v)){
            cout<<cost;
            return 0;
        }
    }
    return 0;
}