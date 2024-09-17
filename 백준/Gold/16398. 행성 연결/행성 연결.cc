#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;

struct Edge{
    ll a,b,cost;

    bool operator<(const Edge& other)const{
        return cost < other.cost;
    } 
};
ll n, answer;
vector<ll> parent(1000+5, -1);
vector<Edge> edge;

ll find(ll x){
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

bool merge(ll a, ll b){
    a = find(a);
    b = find(b);

    if(a == b) return false;
    parent[a] += parent[b];
    parent[b] = a;
    return true;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ll val; cin>>val;
            if(i==j) continue;
            edge.push_back({i,j,val});
        }
    }

    sort(edge.begin(), edge.end());
    ll cnt = 0;
    for(int i=0;i<edge.size(); i++){
        if(merge(edge[i].a, edge[i].b)){
            answer += (ll) edge[i].cost;
            if(++cnt == n-1) break;
        }
    }
    cout<<answer;
    return 0;
}