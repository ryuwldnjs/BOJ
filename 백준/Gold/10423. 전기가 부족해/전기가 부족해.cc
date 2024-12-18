#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Info{
    int u,v,w;

    bool operator<(const Info& other)const{
        return w < other.w;
    }
};
vector<int> parent(1000+5, -1);
vector<Info> edges;
int n,m,k, ans;

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
int main(){
    cin>>n>>m>>k;
    for(int i=0;i<k;i++){
        int x; cin>>x;
        merge(0, x);
    }
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w;
        edges.push_back({u,v,w});
    }
    sort(edges.begin(), edges.end());

    for(auto edge: edges){
        if(merge(edge.u, edge.v)) ans += edge.w;
    }
    cout<<ans;
    return 0;
}