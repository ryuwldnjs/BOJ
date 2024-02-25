#include <bits/stdc++.h>

using namespace std;

//x미만 돌들이 연속적으로 최대 k개 미만라면, x명까지 보장한다는 뜻
bool able(int x, vector<int> & stones, int k){ //징검다리에 x미만 돌들이 최대 k개 미만으로 이루어져 있는가?
    int MAX = 0;
    int tmp = 0;
    for(int i=0;i<stones.size();i++){
        if(stones[i] < x) tmp++;
        else tmp = 0;
        MAX = max(MAX, tmp);
    }
    return MAX < k;
}
int solution(vector<int> stones, int k) {
    int answer = 0;
    int l = 1;
    int r = 1e9;
    
    for(int i=0;i<100;i++){
        int mid = (l+r) / 2;
        if(able(mid, stones, k)) l = mid;
        else r = mid-1;
    }
    // cout<<l<<' '<<r<<'\n'<<able(l,stones, k)<<' '<<able(r,stones,k);
    return able(r,stones,k) ? r : l;
}