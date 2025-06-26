#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

regex pattern("(100+1+|01)+");

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    string a;cin>>a;
    if(regex_match(a, pattern)) cout<<"SUBMARINE\n";
    else cout<<"NOISE\n";
    return 0;
}