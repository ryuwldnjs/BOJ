#include <bits/stdc++.h>
using namespace std;

bool able(int gap, vector<int> &rocks, int n){
    for(int i=0;i<rocks.size();i++){
        for(int j=i+1;j<rocks.size();j++){
            if(rocks[j] - rocks[i] < gap){
                n--;
                if(j==rocks.size()-1) return n>=0;
                continue;
            }
            else{
                i = j-1;
                break;
            }
            i = j;
        }
    }
    return n>=0;
}
int solution(int distance, vector<int> rocks, int n) {
    //출발지점, 도착지점
    rocks.push_back(0);
    rocks.push_back(distance);
    sort(rocks.begin(), rocks.end());
    int l = 1;
    int r = 1e9 + 1;
    for(int i=0;i<100;i++){
        int mid = (l+r) / 2;
        if(able(mid, rocks, n)) l = mid;
        else r = mid - 1;
    }
    
    int answer = able(r, rocks, n) ? r : l;
    return answer;
}