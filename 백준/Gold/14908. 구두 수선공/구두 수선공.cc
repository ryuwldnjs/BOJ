#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int T, S;
    int idx;
    bool operator<(const Info & other)const{
        if(T * other.S == S * other.T) return idx < other.idx;
        return T * other.S < S * other.T;
    }
};

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    vector<Info> jobs(n);
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        jobs[i] = {a, b, i+1};
    }
    sort(jobs.begin(), jobs.end());

    // for(int i=0;i<n;i++){
    //     for(int j=0;j<i;j++){
    //         if(jobs[j+1] < jobs[j]) swap(jobs[j+1], jobs[j]);
    //     }
    // }
    for(int i=0;i<n;i++){
        cout<<jobs[i].idx<<' ';
    }
    return 0;
}