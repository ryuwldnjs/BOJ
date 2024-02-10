#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<pair<int,int>> s;//인덱스와 값
    
    for(int i=0;i<prices.size();i++){
        while(!s.empty() && s.top().second > prices[i]){
            answer[s.top().first] = i - s.top().first;
            s.pop();
        }
        s.push({i, prices[i]});
    }
    
    while(!s.empty()){
        answer[s.top().first] = prices.size() - s.top().first - 1;
        s.pop();
    }
    return answer;
}