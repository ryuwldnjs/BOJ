#include <bits/stdc++.h>
using namespace std;

queue<int> q;
int dist[20000+50];
vector<vector<int>> graph;
int MAX = -2e9;
int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    graph.resize(n+1);
    for(auto v : edge){
        graph[v[0]].push_back(v[1]);
        graph[v[1]].push_back(v[0]);
    }
    
    q.push(1);
    
    while(!q.empty()){
        int now = q.front();
        if(dist[now] > MAX) {
            MAX = dist[now];
            answer = 1;
        }
        else if(dist[now] == MAX) answer++;
        q.pop();
        
        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i];
            if(!dist[next] && next != 1){
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
    
    return answer;
}