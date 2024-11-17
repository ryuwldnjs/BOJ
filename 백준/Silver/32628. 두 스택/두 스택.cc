#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
ll n,k;
vector<ll> a,b,psum_a,psum_b; 
ll MIN = 1e18;
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n>>k;
    a.resize(n+1);
    b.resize(n+1);
    psum_a.resize(n+1);
    psum_b.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        psum_a[i] = psum_a[i-1] + a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
        psum_b[i] = psum_b[i-1] + b[i];
    }
    for(int i=0;i<=k;i++){
        if(n - i < 0 ||  n - k + i < 0) continue;
        MIN = min(MIN, max(psum_a[n - i], psum_b[n - k + i]));
    }
    cout<<MIN;
    return 0;
}