#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

void solve(){

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n,k;cin>>n>>k;

    ll num = 0;
    ll len = 1;
    while(true){
        ll next_num = num*10 + 9;
        if((next_num - num) * len < k){
            k -= (next_num - num) * len;
            num = next_num;
            len++;
        }
        else break;
    }

    num += k / len;
    k %= len;

    if(num>n || num==n&&k>0){
        cout<<-1;
        return 0;
    }

    string answer;
    if(k == 0) answer = to_string(num)[len-1];
    else answer = to_string(num+1)[k-1];

    cout<<answer;
    return 0;
}