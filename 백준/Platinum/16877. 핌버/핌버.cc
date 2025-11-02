#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int SIZE = 3*1000000 + 5;
ll fibo[105];
ll grundy[4000000];
//님게임으로 치환

void preprocess(){
    fibo[0] = fibo[1] = 1;
    for(int i=2;i<100;i++){
        fibo[i] = fibo[i-1] + fibo[i-2];
    }


    grundy[0] = 0;
    bool seen[100] = {};
    for(int i=1;i<SIZE;i++){
        memset(seen, 0, sizeof(seen));

        for(int j=1;j<100;j++){
            int idx = i - fibo[j];
            if(idx < 0) break;
            seen[grundy[idx]] = true;
        }

        ll mex = 0;
        for(int i=0;i<100;i++){
            if(seen[i]) mex++;
            else break;
        }

        grundy[i] = mex;
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    preprocess();
    ll n;cin>>n;
    ll nim = 0;
    for(int i=0;i<n;i++){
        ll x;cin>>x;
        nim ^= grundy[x];
    }

    if(nim) cout<<"koosaga";
    else cout<<"cubelover";
    return 0;
}