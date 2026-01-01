#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n,k;
int a[100000+5];

bool able(int x){
    int cnt=0; //x이상 그룹의 개수
    int sum=0; //현재 그룹의 맞은수
    for(int i=0;i<n;i++){
        sum += a[i];
        if(sum >= x){
            sum = 0;
            cnt++;
        }
    }
    return cnt >= k;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>k;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int lo=1, hi=4000000;
    for(int i=0;i<100;i++){
        int mid = (lo + hi) / 2;
        if(able(mid)) lo = mid;
        else hi = mid;
    }

    cout<<lo;
    return 0;
}