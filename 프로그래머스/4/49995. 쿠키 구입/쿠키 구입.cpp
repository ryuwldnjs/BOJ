#include<bits/stdc++.h>

using namespace std;

int solution(vector<int> cookie) {
    int answer = 0;
    cookie.insert(cookie.begin(), 0);
    vector<int> psum(cookie.size());
    
    for(int i=1;i<cookie.size();i++){
        psum[i] = psum[i-1] + cookie[i];
    }
    for(int i=1;i<psum.size();i++){
        for(int j=i+1;j<psum.size();j++){
            int psum_val = psum[j] - psum[i-1];
            if(psum_val%2) continue;
            if(binary_search(psum.begin()+i, psum.begin()+j+1, psum_val/2 + psum[i-1]))
                answer = max(answer, psum_val/2);
        }
    }
    return answer;
}