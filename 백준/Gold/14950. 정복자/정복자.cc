#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int a,b,cost;
    bool operator<(const Info &other)const{
        return cost < other.cost;

    }
};

vector<Info> edge;
vector<int> parent;
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
    cin.tie(0) -> sync_with_stdio(0);
    int n,m,t;cin>>n>>m>>t;
    parent.resize(n+1, -1);

    for(int i=0;i<m;i++){
        int a,b,c;cin>>a>>b>>c;
        edge.push_back({a,b,c});
    }

    sort(edge.begin(), edge.end());

    int answer = 0;
    int extra = 0;
    for(auto [a,b,c] : edge){
        if(merge(a,b)){
            answer += c + extra;
            extra += t;
        }
    }

    cout<<answer;
    return 0;
}