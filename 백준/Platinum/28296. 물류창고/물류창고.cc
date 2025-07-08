#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Edge{
    ll a,b;
    ll cost;

    //내림차순
    bool operator<(const Edge & other)const{
        return cost > other.cost;
    }
};

int n,k,m;
vector<Edge> edges;
vector<ll> parent, answer;//회사 단위별 정답
vector<map<int,ll>> component;


int find(int x){
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

//i가 루트인 컴포넌트의 회사들 정보
int merge(int a, int b, ll cost){
    a = find(a);
    b = find(b);

    if(a == b)return 0;

    //회사단위로 small to large
    if(component[a].size() < component[b].size()) swap(component[a], component[b]);
    
    for(auto it=component[b].begin(); it!=component[b].end(); it++){
        int company = it->first;
        int val = it->second;
        answer[company] += cost * component[a][company] * component[b][company];
        component[a][company] += val;
    }

    parent[a] += parent[b];
    parent[b] = a;
    return 1;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>k>>m;
    parent.resize(n+1, -1);
    component.resize(n+1);
    answer.resize(k+1);

    for(int i=1;i<=n;i++){
        int company; cin>>company;
        component[i][company]++;
        //i공장이 루트인 컴포넌트에 회사정보 추가
    }
    for(int i=0;i<m;i++){
        ll a,b,c;cin>>a>>b>>c;
        edges.push_back({a,b,c});
    }

    sort(edges.begin(), edges.end());

    for(Edge& e: edges){
        merge(e.a, e.b, e.cost);
    }

    for(int i=1;i<=k;i++){
        cout<<answer[i]<<'\n';
    }
    return 0;
}