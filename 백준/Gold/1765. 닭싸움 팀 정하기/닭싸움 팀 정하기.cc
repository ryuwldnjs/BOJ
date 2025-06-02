#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;


vector<int> parent;
vector<vector<int>> enemies;
int find(int x){
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}
bool merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return false;
    parent[a] += parent[b];
    parent[b] = a;
    return true;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin>>n>>m;
    parent.resize(n+1, -1);
    enemies.resize(n+1);

    for(int i=0;i<m;i++){
        char a; int b,c; cin>>a>>b>>c;
        if(a == 'F') merge(b,c);
        else {
            enemies[b].push_back(c);
            enemies[c].push_back(b);
        }
    }

    for(int i=1;i<=n;i++){
        //원수끼리끼리
        for(int j=1;j<enemies[i].size();j++){
            merge(enemies[i][j-1], enemies[i][j]);
        }
    }

    int answer = 0;
    for(int i=1;i<=n;i++){
        if(find(i) == i) answer++;
    }
    cout<<answer;
    return 0;
}