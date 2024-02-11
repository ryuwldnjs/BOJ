#include <string>
#include <vector>

using namespace std;
bool visited[205];

void dfs(int now, int n, vector<vector<int>> &computers){
    visited[now] = true;
    for(int i=0;i<n;i++){
        if(computers[now][i] && !visited[i]) dfs(i, n, computers);
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
            dfs(i, n, computers);
            answer++;
        }
    }
    return answer;
}