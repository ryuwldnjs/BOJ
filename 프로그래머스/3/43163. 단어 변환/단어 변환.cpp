#include <bits/stdc++.h>
using namespace std;
using psi=pair<string,int>;
queue<psi> q;
bool visited[55];

int getDist(string a, string b){
    int cnt = 0;
    for(int i=0;i<a.size();i++){
        if(a[i] != b[i]) cnt++;
    }
    return cnt;
}

int solution(string begin, string target, vector<string> words) {
    q.push({begin, 0});
    
    while(!q.empty()){
        string now = q.front().first;
        int cost = q.front().second;
        q.pop();
        
        if(now == target) return cost;
        
        for(int i=0;i<words.size();i++){
            if(getDist(now, words[i]) == 1 && !visited[i]){
                visited[i] = true;
                q.push({words[i], cost + 1});
            }
        }
    }
    return 0;
}