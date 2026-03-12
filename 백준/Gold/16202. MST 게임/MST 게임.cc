#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Edge{
    int a,b;
    bool isDeleted;
};

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

int n,m,k;
vector<Edge> edges(10000+5);


int solve(){
    int cnt = 0;
    int ret = 0;
    Edge *target = NULL;
    for(int i=1;i<=m;i++){
        if(edges[i].isDeleted) continue;
        if(merge(edges[i].a, edges[i].b)){
            cnt++;
            ret += i;
            if(target == NULL) target = &edges[i]; 
        }
    }
    
    if(cnt != n-1) return 0;

    target->isDeleted = true;
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        int a,b;cin>>a>>b;
        edges[i] = {a,b, false};
    }


    while(k--){
        parent = vector<int>(n+1, -1);
        cout<<solve()<<' ';
    }
    return 0;
}