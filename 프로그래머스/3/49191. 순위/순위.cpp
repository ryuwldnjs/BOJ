#include <bits/stdc++.h>
using namespace std;
queue<int> q;
bool visited[105];

int dfs(int now, vector<vector<int>> & graph){
    visited[now] = true;
    int traverse = 1;
    for(int i=0;i<graph[now].size(); i++){
        int next = graph[now][i];
        if(!visited[next]) traverse += dfs(next, graph);
    }
    return traverse;
}
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> in(n+1), out(n+1); //서로 반대 방향의 DAG형성
    vector<int> indegree(n+1);
    
    for(auto x : results){
        int s = x[1];
        int e = x[0];
        in[e].push_back(s);//e로 들어오는 s들
        out[s].push_back(e);//s에서 나가는 e들
    }
    
    for(int i=1;i<=n;i++){
        int traverse = 0;
        int a,b;
        fill(&visited[1], &visited[n+1], false);
        traverse += dfs(i, in);
        fill(&visited[1], &visited[n+1], false);
        traverse += dfs(i, out);
        
        if(traverse == n+1) answer++;
    }
    
    return answer;
}