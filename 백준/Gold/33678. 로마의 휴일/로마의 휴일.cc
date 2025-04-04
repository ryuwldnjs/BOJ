#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;
int main(){
    ll n,k,x; cin>>n>>k>>x;
    vector<ll> arr(n+1), psum(n+1);
    for(ll i=1;i<=n;i++){
        cin>>arr[i];
        psum[i] = psum[i-1] + x*arr[i];
    }

    ll answer = 0, sum=0;
    //[i,n-1]일을 할때, 초반 특근을 가장 적게 하는 경우
    for(ll i=n+1;i>1;i--){
        
        if(i<=n) sum += arr[i];//휴가 다녀온 후 임금
        ll target = lower_bound(psum.begin(), psum.end(), k - sum) - psum.begin();
        if(target >= i) continue;

        if(psum[target] + sum >= k){
            answer = max(answer, i - target - 1);
        }
    }
    //휴가 다녀온 후 휴가 안갈때
    if(answer == 0) answer = -1;
    cout<<answer;
    return 0;
}