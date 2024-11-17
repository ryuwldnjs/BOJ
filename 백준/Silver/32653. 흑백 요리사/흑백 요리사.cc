#include <iostream>
using namespace std;
using ll= long long;
ll n,ans=1;
ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        ll x; cin>>x;
        x<<=1;
        ans = ans * x / gcd(ans, x);
    }
    cout<<ans;
    return 0;
}