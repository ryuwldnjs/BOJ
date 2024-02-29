#include <bits/stdc++.h>
using namespace std;
struct info{
    int start;
    int time;
    const bool operator< (const info& tmp) const{
        return time > tmp.time;
    }
};

int solution(vector<vector<int>> jobs) {
    sort(jobs.begin(), jobs.end());
    priority_queue<info> pq;
    int answer = 0;
    int last = jobs[0][0];
    int idx = 1;
    pq.push({jobs[0][0], jobs[0][1]});
    
    while(true){
        if(pq.empty() && idx == jobs.size()) break;
        if(pq.empty()){ //겹치지 않는 스케줄일때
            pq.push({jobs[idx][0], jobs[idx][1]});
            last = jobs[idx][0];
            idx++;
        }
        auto top = pq.top();
        pq.pop();
        
        while(idx < jobs.size()){
            if(jobs[idx][0] <= last + top.time){
                pq.push({jobs[idx][0], jobs[idx][1]});
                idx++;
            }
            else break;
        }
        last += top.time;
        answer += last - top.start; //각 스케줄의 총 소요시간 합산
    }
    return answer / jobs.size();
}