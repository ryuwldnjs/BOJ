#include <iostream>
using namespace std;
using ll=long long;
ll n,k,answer=1;
int main(){
    cin>>n>>k;
    n--;k--;
    if(k > n/2) k = n-k;
    for(ll i=n;i>n-k;i--) answer *= i;
    // cout<<answer<<'\n';
    for(ll i=1;i<=k;i++) answer /= i;
    cout<<answer;
    return 0;
}