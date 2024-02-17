#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int idx, t, capacity, through, length;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    for(int i=0;i<bridge_length;i++) q.push(0);
    
    while(!q.empty()){
        t++;
        if(q.front() > 0){
            capacity -= q.front();
            length--;
            if(++through == truck_weights.size()) return t;
        }
        q.pop();
        
        if(length < bridge_length && capacity + truck_weights[idx] <= weight){
            q.push(truck_weights[idx]);
            capacity += truck_weights[idx++];
            length++;
        }
        else q.push(0); // 빈 공간 채워넣기
    }
    
    return t;
}