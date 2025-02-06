#include <iostream>
#include <vector>
using namespace std;
struct Info{
    int idx, cost;
};
vector<int> parent, dist;
int n;
Info find(int x){
    if(parent[x] < 0) return {x, dist[x]};
    Info tmp = find(parent[x]);
    parent[x] = tmp.idx;
    dist[x] += tmp.cost;
    return {parent[x], dist[x]};
}
int merge(int a, int b, int c){
    int p_a = find(a).idx;
    int p_b = find(b).idx;
    if(p_a == p_b) return 0;
    parent[p_a] += parent[p_b];
    parent[p_b] = p_a;
    // c -= dist[b];
    dist[p_b] = c + dist[a] - dist[b];
    return 1;
}
void query(int a, int b){
    int p_a = find(a).idx;
    int p_b = find(b).idx;

    if(p_a == p_b){
        cout<<dist[b] - dist[a]<<'\n';
    }
    else{
        cout<<"UNKNOWN\n";
    }
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    while(true){
        int m; cin>>n>>m;
        parent = vector<int>(n+1, -1);
        dist = vector<int>(n+1);
        if(n==0 && m==0) break;

        while(m--){
            string cmd; cin>>cmd;
            int a,b,c;
            if(cmd=="!"){
                cin>>a>>b>>c;
                merge(a,b, c);
            }
            else{
                cin>>a>>b;
                query(a,b);
            }
        }
    }
    return 0;
}