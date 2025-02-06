#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, dist;
int n;
int find(int x){
    if(parent[x] < 0) return x;
    int p = find(parent[x]);
    dist[x] += dist[parent[x]];
    return parent[x] = p;
}
int merge(int a, int b, int c){
    int p_a = find(a);
    int p_b = find(b);
    if(p_a == p_b) return 0;
    parent[p_a] += parent[p_b];
    parent[p_b] = p_a;
    
    dist[p_b] = c + dist[a] - dist[b];
    return 1;
}
void query(int a, int b){
    if(find(a) == find(b)){
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