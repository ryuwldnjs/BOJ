#include <string>
#include <vector>
#include <queue>
using namespace std;
vector<int> dist(500000+5, -1);
vector<vector<int>> graph;
queue<int> q;
void BFS(int start){
    dist[start] = 0;
    q.push(start);
    
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(int i=0;i<graph[now].size();i++){
            int next = graph[now][i];
            
            if(dist[next] == -1){
                dist[next] = dist[now] + 1;
                q.push(next);
            }
        }
    }
    
    
}
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    graph.resize(n+1);
    for(auto road : roads){
        int a = road[0];
        int b = road[1];
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    BFS(destination);
    for(auto start : sources){
        answer.push_back(dist[start]);
    }
    return answer;
}