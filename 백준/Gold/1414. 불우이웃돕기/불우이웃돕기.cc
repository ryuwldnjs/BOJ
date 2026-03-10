#include <bits/stdc++.h>
using namespace std;
struct Edge{
    int a,b,cost;
    bool operator<(const Edge& other)const{
        return cost < other.cost;
    }
};

vector<int> parent(55, -1);
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

vector<Edge> edges;
int main(){
    cin.tie(0) -> sync_with_stdio(0);

    int n;cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c;cin>>c;
            if(c == '0') continue;
            if('a'<=c&&c<='z') edges.push_back({i,j, c-'a'+1});
            if('A'<=c&&c<='Z') edges.push_back({i,j, c-'A'+27});
        }
    }

    sort(edges.begin(), edges.end());

    int answer = 0;
    for(auto [a,b,cost] : edges){
        if(merge(a,b)){
            n--;
        }
        else answer += cost;

    }

    if(n > 1) cout<<-1;
    else cout<<answer;
    return 0;
}