#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n,m;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m;

    n %= m; //일단 슬라이싱 없이 공평하게 나눌수있음

    int GCD = gcd(n,m);

    int answer = m - GCD;
    cout<<answer;
    return 0;
}