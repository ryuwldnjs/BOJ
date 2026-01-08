#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define INF 1e9

int n,m;
int a[5005];
//구간의점수가 x이하인 구간 m개이하를 만들수있는가?
// F F T T
bool able(int x){
    int cnt = 1;
    int MIN=INF, MAX=-INF;

    for(int i=0;i<n;i++){
        MIN = min(MIN, a[i]);
        MAX = max(MAX, a[i]);
        if(MAX-MIN > x){
            MIN = a[i];
            MAX = a[i];
            cnt++;
        }
    }
    return cnt <= m;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];


    int lo=0, hi=10000;
    for(int i=0;i<100;i++){
        int mid = (lo + hi) / 2;
        if(able(mid)) hi = mid;
        else lo = mid; 
    }

    cout<<hi;
    return 0;
}