#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    while(pq.size()>=2 && pq.top() < K){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        pq.push(a + 2*b);
    }
    
    return pq.top() >= K ? scoville.size() - pq.size() : -1;
}