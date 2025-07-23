#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

ll n,answer;
ll getValue(ll k){
    return (n-1) / k + 1;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;

    ll MAX;

    answer = n;//k=1
    for(ll i=2;i<n; i=MAX+1){
        MAX = (n-1) / ((n-1) / i);
        answer += (MAX - i + 1) * getValue(i);
    }
    
    if(n > 1) answer++; //k=n

    cout<<answer;
    return 0;
}