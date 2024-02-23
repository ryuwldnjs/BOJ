#include <bits/stdc++.h>

using namespace std;

bool able(int criteria, vector<int> & works, int n){ //모든 일들을 criteria시간 이하로 만들수 있는가?
    for(int i=0;i<works.size();i++){
        n -= max(works[i] - criteria, 0);
    }
    return n>=0;
}
long long solution(int n, vector<int> works) {
    int l = 0;
    int r = 100000;
    for(int i=0;i<100;i++){
        int mid = (l+r) / 2;
        if(able(mid, works, n)) r = mid;
        else l = mid + 1;
    }
    int cnt = 0;
    long long score = 0;
    // int cnt_
    for(int i=0;i<works.size();i++){
        cnt += max(works[i] - l, 0);
        works[i] = min(works[i], l);
        score += works[i] * works[i];
    }
    if(cnt == n) return score;
    else{ // 더 쳐낼 수 있을때
        score = 0;
        for(int i=0;i<works.size();i++){
            if(works[i]==l && cnt++ < n) works[i] = max(works[i]-1, 0);
            score += works[i] * works[i];
        }
    }
    return score;
}