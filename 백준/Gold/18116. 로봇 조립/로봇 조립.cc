#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<int> parent(1000000+5, -1);
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

int getSize(int x){
    x = find(x);
    return -parent[x];
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        char com; int a,b;
        cin>>com;
        
        if(com == 'I'){
            cin>>a>>b;
            merge(a,b);
        }
        else{
            cin>>a;
            cout<<getSize(a)<<'\n';
        }
    }


    return 0;
}