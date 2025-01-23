#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9
using namespace std;


vector<vector<int>> dist, groups;
vector<int> answer, parent;
int n,m;
void floyd(){
    for(int i=1;i<=n;i++) dist[i][i] = 0;

    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    return;
}
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

int findPresident(vector<int>& group){
    int MIN=1e9, MIN_id=0;
    for(int i=0;i<group.size();i++){
        int cost = -1e9;
        for(int j=0;j<group.size();j++){
            int a = group[i];
            int b = group[j];
            cost = max(cost, dist[a][b]);
        }
        if(MIN > cost){
            MIN = cost;
            MIN_id = group[i];
        }
    }
    return MIN_id;
}
int main(){
    cin>>n>>m;
    dist.resize(n+1, vector<int>(n+1, INF));
    parent.resize(n+1, -1);
    groups.resize(n+1);
    for(int i=0;i<m;i++){
        int a,b; cin>>a>>b;
        dist[a][b] = dist[b][a] = 1;
        merge(a,b);
    }

    floyd();
    for(int i=1;i<=n;i++){
        groups[find(i)].push_back(i);
    }
    for(auto group: groups){
        if(group.empty()) continue;
        // int president = findPresident(group);
        answer.push_back(findPresident(group));
    }
    sort(answer.begin(), answer.end());
    cout<<answer.size()<<'\n';
    for(auto x : answer) cout<<x<<'\n';
    return 0;
}