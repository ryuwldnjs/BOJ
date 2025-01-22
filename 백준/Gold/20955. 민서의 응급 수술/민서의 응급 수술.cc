#include <iostream>
#include <vector>
using namespace std;

vector<int> parent;
int n,m, success;

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
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>m;
    parent = vector<int>(n+1, -1);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        if(merge(a,b)) success++;
    }


    cout<<n-1-success + (m-success);
}