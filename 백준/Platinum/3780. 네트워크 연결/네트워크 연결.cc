#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int pid;
    int dist;
};
const int MOD = 1000;
vector<Info> parent;
Info find(int x){
    if(parent[x].pid < 0) return {x, 0}; //최상단 루트

    Info tmp = find(parent[x].pid);
    return parent[x] = {tmp.pid, parent[x].dist + tmp.dist};
}

//센터a를 b에 연결하기
int merge(int a, int b){
    // a = find(a).pid;
    Info pb = find(b);
    // int b_dist = find(b).dist;
    // b = find(b).pid;

    // if(a == b) return 0;

    // parent[b] += parent[a];
    parent[a] = {pb.pid, abs(a-b) % MOD + pb.dist};
    return 1;
}

void solve(){
    int n;cin>>n;
    parent = vector<Info>(n+1, {-1, 0});

    while(true){
        char com;
        int a,b;
        cin>>com;
        if(com == 'O') break;
        if(com == 'E'){
            cin>>a;
            cout<<find(a).dist<<'\n';
        }
        if(com == 'I'){
            cin>>a>>b;
            merge(a, b);
        }
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}