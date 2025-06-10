#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n,q;
vector<int> parent;

int find(int x){
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}
int merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a < b) swap(a,b);
    if(a == b) return 0;
    parent[a] += parent[b];
    parent[b] = a;
    return 1;
}

//2SAT + DSU
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>q;
    parent.resize(2*(n+2), -1);

    int answer = 0;
    while(q--){
        int a,b;cin>>a>>b;

        if(find(a*2+1)==find(b*2)){
            cout<<answer/2<<'\n';
            continue;
        }

        if(find(a*2) == find(a*2+1)) answer -= -parent[find(a*2)];
        if(find(b*2) == find(b*2+1)) answer -= -parent[find(b*2)];

        merge(a*2, b*2+1);
        merge(b*2, a*2+1);

        if(find(a*2) == find(a*2+1)){ //홀수 사이클 존재
            answer += -parent[find(a*2)];
        }
        cout<<answer/2<<'\n';
    }

    return 0;
}