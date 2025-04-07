#include <iostream>
#include <cassert>
using namespace std;
using ll=long long;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
ll s,x,m,d,k;

int main(){
    cin>>s>>x>>m>>d>>k;
    ll GCD = gcd(x, m);
    s %= GCD;
    ll target = m - 1 - (m - 1 - s) % GCD;
    if(target == 0){
        cout<<0;
        return 0;
    }
    ll frequency = k / target;

    ll answer  = (d - 1) / frequency;
    cout<<answer;
    return 0;
}