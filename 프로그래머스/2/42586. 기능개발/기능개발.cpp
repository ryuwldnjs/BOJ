#include <bits/stdc++.h>

using namespace std;
queue<pair<int,int>> q; // index, value
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    for(int i=0;i<progresses.size();i++) q.push({i, progresses[i]});
    
    while(!q.empty()){
        int n = q.size();
        int deploy = 0;
        while(n--){
            auto front = q.front();
            if(front.second + speeds[front.first] >= 100 
               && q.size() + front.first == progresses.size()) deploy++;
            else q.push({front.first, front.second + speeds[front.first]});
            q.pop();
        }
        if(deploy) answer.push_back(deploy);
    }
    return answer;
}