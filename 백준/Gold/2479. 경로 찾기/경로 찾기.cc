#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<string> codes;
vector<vector<int>> graph;
int n,k;

int getDist(string &a, string &b){
    int diff = 0;
    for(int i=0;i<k;i++){
        if(a[i] != b[i]) diff++;
    }
    return diff;
}

void bfs(int start, int end){
    queue<int> q;
    vector<bool> visited(n);
    vector<int> parent(n, -1);

    q.push(start);
    visited[start] = true;
    while(!q.empty()){
        int now = q.front(); q.pop();
        // printf("%d\n", now);
        for(int next: graph[now]){
            if(!visited[next]){
                q.push(next);
                parent[next] = now;
                visited[next] = true;
            }
        }
    }

    if(parent[end] == -1) {
        cout<<-1;
        return;
    }

    vector<int> answer;
    for(int now=end; now!=-1; now = parent[now]){
        answer.push_back(now);
    }
    reverse(answer.begin(), answer.end());



    for(int i : answer){
        cout<<i+1<<' ';
    }

}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>k;
    codes.resize(n);
    graph.resize(n);

    for(int i=0;i<n;i++){
        cin>>codes[i];
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(getDist(codes[i], codes[j]) == 1){
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    int s,e; cin>>s>>e;
    bfs(s-1, e-1);
    return 0;
}