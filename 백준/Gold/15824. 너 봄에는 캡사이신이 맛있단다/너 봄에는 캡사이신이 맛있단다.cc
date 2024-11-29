#include <iostream>
#include <vector>
#include <algorithm>
#define MOD 1000000007
using namespace std;
using ll=long long;
ll n, ans;
vector<ll> arr, psum;
// [l,r] 폐구간 
ll getPsum(int l, int r){
    return psum[r] - psum[l-1];
}
// val^exp꼴
ll getPower(ll val, ll exp){
    if(exp == 0) return 1;
    ll tmp = (getPower(val, exp/2)) % MOD;
    if(exp % 2 == 0) return (tmp * tmp) % MOD;
    else return (tmp * tmp * val) % MOD;
}
int main(){
    cin>>n;
    arr.resize(n+1); psum.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr.begin()+1, arr.end());
    for(int i=1;i<=n;i++){
        psum[i] = psum[i-1] + arr[i];
    }

    for(int i=0;i<n-1;i++){
        ll sum = (getPsum(n-i, n) - getPsum(1, 1+i)) % MOD;
        // sum = (sum<<i) % MOD;
        sum = (sum * getPower(2, i)) % MOD;
        ans = (ans + sum) % MOD;
    }
    cout<<ans;
    return 0;
}