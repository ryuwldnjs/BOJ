#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
ll priority[3];
struct Line{
    ll u,v,w,k;

    const bool operator<(const Line& other) const{
        if(w == other.w) return priority[k] < priority[other.k];
        return w < other.w;
    }
};
vector<ll> parent(10000+5, -1);
ll find(ll x){
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}
ll merge(ll a, ll b){
    a = find(a);
    b = find(b);
    if(a == b) return 0;
    parent[a] += parent[b];
    parent[b] = a;
    return 1;
}
ll n,m;
ll cnt[3], cost[3];
vector<Line> line;
int main(){
    cin>>n>>m;
    for(int i=0;i<3;i++){
        ll p; cin>>p;
        priority[p] = i;
    }
    for(int i=0;i<m;i++){
        ll u,v,w,k; cin>>u>>v>>w>>k;
        line.push_back({u,v,w,k});
    }
    sort(line.begin(), line.end());

    for(int i=0;i<line.size(); i++){
        if(merge(line[i].u, line[i].v)){
            cnt[line[i].k]++;
            cost[line[i].k] += line[i].w;
        }
    }
    cout<<cost[0]+cost[1]+cost[2]<<'\n';
    cout<<cnt[0]<<' '<<cost[0]<<'\n';
    cout<<cnt[1]<<' '<<cost[1]<<'\n';
    cout<<cnt[2]<<' '<<cost[2]<<'\n';
    return 0;
}