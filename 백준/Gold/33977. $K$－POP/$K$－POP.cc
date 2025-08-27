#include <bits/stdc++.h>

using namespace std;

using ll=long long;

using pii=pair<int,int>;

using pll=pair<ll,ll>;

int getPrime(int x){

    int ret = 1;

    for(int i=2;i*i<=x;i++){

        if(x % i == 0) ret = i;

    }

    return ret;

}

void solve(){

    int n;cin>>n;

    int a = getPrime(n); // 자식 2개짜리

    int b = n / a;

    cout<<a + b<<'\n';

    int start = 1;

    for(int i=1;i<a;i++){

        cout<<i<<' '<<2*i<<'\n';

        cout<<i<<' '<<2*i+1<<'\n';

        start = 2*i+1;

    }

    for(int i=start;i<=start+b-a;i++){

        cout<<i<<' '<<i+1<<'\n';

    }

}

int main(){

    cin.tie(0) -> sync_with_stdio(0);

    solve();

    return 0;

}