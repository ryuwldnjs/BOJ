#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<ll> arr,psum;
int n;

ll solve(int l, int r){
    if(l == r) return arr[l] * arr[l];
    ll ret = 0;
    int mid = (l+r)/2;
    ret = max(ret, solve(l, mid));
    ret = max(ret, solve(mid+1, r));

    int lo=mid;
    int hi=mid+1;
    ll MIN = min(arr[lo], arr[hi]);

    while(l < lo || hi < r){
        MIN = min(MIN, min(arr[lo], arr[hi]));
        ret = max(ret, (psum[hi] - psum[lo-1]) * MIN);
        // printf("%d %d: %d\n",lo,hi,ret);
        if(hi < r && (lo == l || arr[hi+1] >= arr[lo-1])) hi++;
        else if(lo > l && (hi == r || arr[lo-1] >= arr[hi+1])) lo--;
    }
    MIN = min(MIN, min(arr[l], arr[r]));
    ret = max(ret, (psum[r] - psum[l-1]) * MIN);

    return ret;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    arr.resize(n+2);
    psum.resize(n+2);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        psum[i] = psum[i-1] + arr[i];
    }

    cout<<solve(1, n);
    return 0;
}