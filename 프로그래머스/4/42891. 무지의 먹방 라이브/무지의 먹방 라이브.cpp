#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int solution(vector<int> food_times, ll k) {
    vector<int> sorted_time = food_times;
    sort(sorted_time.begin(), sorted_time.end());
    
    ll turn = 0;
    ll total_time = 0;
    for(int i=0;i<sorted_time.size();i++){
        ll remain = sorted_time.size() - i;
        ll cost = remain * (sorted_time[i] - turn);
        
        if(total_time + cost <= k){
            total_time += cost;
            turn += sorted_time[i] - turn;
        }
        else {
            total_time += (k - total_time) / remain * remain;
            turn += (k - total_time) / remain;
            break;
        }
        
    }
    
    for(int i=0;i<food_times.size();i++){
        if(food_times[i] > turn && total_time++ == k) return i+1;
    }
    return -1;
}