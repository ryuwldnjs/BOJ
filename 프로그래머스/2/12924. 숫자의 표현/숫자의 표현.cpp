#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    vector<int> psum(10000+1, 0);
    int answer = 0;
    for(int i=1;i<10000+1;i++) psum[i] = psum[i-1] + i;
    for(int i=0;i<10000+1;i++){
        if(binary_search(psum.begin(), psum.end(), n+psum[i])) answer += 1;
    }
    // int l = 0;
    // int r = 1;
    // while(l<r){
    //     int sum = psum[r] - psum[l];
    //     if(sum == n) answer++;
    //     if(sum >= n) l++;
    //     else r++;
    // }
    return answer;
}