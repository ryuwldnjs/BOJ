#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define INF 1e9

int n,l,r,x;
int a[20];

bool canSelect(int bit){
    int cnt = 0;
    int sum = 0;
    int MIN = INF;
    int MAX = -INF;

    for(int i=0;i<n;i++){
        if((1<<i) & bit){ //켜진 비트만
            cnt++;
            sum += a[i];
            MIN = min(MIN, a[i]);
            MAX = max(MAX, a[i]);
        }
    }

    return cnt>=2 && l<=sum&&sum<=r && MAX-MIN>=x;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>l>>r>>x;
    for(int i=0;i<n;i++) cin>>a[i];


    int answer = 0;
    for(int bit=0;bit<(1<<n);bit++){
        if(canSelect(bit)) answer++;
    }

    cout<<answer;
    return 0;
}