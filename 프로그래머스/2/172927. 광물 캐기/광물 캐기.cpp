#include <bits/stdc++.h>

using namespace std;
int cost[3][3] = {
    {1,1,1},
    {5,1,1},
    {25,5,1}
};
int solve(int idx, int n, vector<int> &picks, vector<int> &list, vector<string> & minerals){
    int answer = 100000;
    if(idx == n){
        answer = 0;
        for(int i=0; i<minerals.size() && i/5 < list.size();i++){
            if(minerals[i] == "diamond") answer += cost[list[i/5]][0];
            if(minerals[i] == "iron") answer += cost[list[i/5]][1];
            if(minerals[i] == "stone") answer += cost[list[i/5]][2];
        }
        return answer;
    }
    for(int i=0;i<3;i++){
        if(picks[i]){
            picks[i]--;
            list.push_back(i);
            answer = min(answer, solve(idx+1, n, picks, list, minerals));
            picks[i]++;
            list.pop_back();
            
        }
        
    }
    return answer;
}
int solution(vector<int> picks, vector<string> minerals) {
    vector<int> list;
    return solve(0, picks[0]+picks[1]+picks[2], picks, list, minerals);
}