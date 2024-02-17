#include <bits/stdc++.h>

using namespace std;

bool cmp(vector<int> &a, vector<int> &b){
    return a[1] < b[1];
}
int solution(vector<vector<int>> routes) {
    int answer = 0;
    int pre = -100000;
    sort(routes.begin(), routes.end(), cmp);
    
    for(auto route: routes){
        if(pre < route[0]){
            answer++;
            pre = route[1];
        }
    }
    return answer;
}