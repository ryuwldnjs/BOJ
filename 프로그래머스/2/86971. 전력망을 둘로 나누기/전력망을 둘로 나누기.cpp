#include <bits/stdc++.h>
using namespace std;

bool visited[105];
vector<vector<int>> graph(105);
int MIN = 2e9;
int dfs(int now){
    int cnt = 1;
    visited[now] = true;
    for(int next : graph[now]){
        if(!visited[next]) cnt += dfs(next);
    }
    return cnt;
}
int solution(int n, vector<vector<int>> wires) {
    for(auto wire : wires){
        graph[wire[0]].push_back(wire[1]);
        graph[wire[1]].push_back(wire[0]);
    }
    for(auto wire : wires){
        //이번 wire를 끊었을때, 한쪽 컴포넌트의 노드 개수 구하기
        fill(&visited[0], &visited[n+1], false);    
        visited[wire[0]] = true;
        MIN = min(MIN, abs(n - 2*dfs(wire[1])) ); // cnt, n-cnt의 차
    }
    return MIN;
}