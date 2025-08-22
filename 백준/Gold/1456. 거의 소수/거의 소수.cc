#include <bits/stdc++.h>
using namespace std;
using ll= long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int MAX = 1e7 + 5;
bool isPrime[MAX + 5];
void era(){
    memset(isPrime, true, sizeof(isPrime));
    
    isPrime[0] = isPrime[1] = false;
    for(int i=2; i<=MAX; i++){
        if(!isPrime[i]) continue;
        for(int j=i*2; j<=MAX; j+=i){
            isPrime[j] = false;
        }
    }


}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    era();

    ll a,b;cin>>a>>b;

    ll answer = 0;
    for(ll i=2; i*i<=b; i++){
        if(!isPrime[i]) continue;
        for(ll j=i*i; j<=b; j*=i){
            answer++;
            if(LLONG_MAX / j < i) break;//오버플로 방지
        }
    }


    for(ll i=2; i*i<a; i++){
        if(!isPrime[i]) continue;
        for(ll j=i*i; j<a; j*=i){
            answer--;
            if(LLONG_MAX / j < i) break;//오버플로 방지
            
        }
    }

    cout<<answer;
    return 0;
}