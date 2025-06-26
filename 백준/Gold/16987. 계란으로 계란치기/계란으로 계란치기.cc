#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<int> w;
int n;
int solve(int idx, vector<int> &s){
    int ret = 0;
    if(idx == n){
        for(int i=0;i<n;i++){
            if(s[i] <= 0) ret++;
        }
        return ret;
    }
    
    //이미 깨져있으면 패스
    if(s[idx] <= 0) return solve(idx+1, s);
    
    bool isHitted = false;
    for(int i=0;i<n;i++){
        if(i == idx || s[i] <= 0) continue;
        isHitted = true;
        s[i] -= w[idx]; s[idx] -= w[i];
        ret = max(ret, solve(idx+1, s));
        s[i] += w[idx]; s[idx] += w[i];
    }
    if(!isHitted) ret = max(ret, solve(idx+1, s));
    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    vector<int> s(n);
    w.resize(n);
    for(int i=0;i<n;i++){
        cin>>s[i]>>w[i];
    }


    cout<<solve(0, s);
    return 0;
}