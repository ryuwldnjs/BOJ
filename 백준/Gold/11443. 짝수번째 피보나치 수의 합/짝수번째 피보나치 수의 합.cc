#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll MOD = 1000000007;

struct Matrix{
    vector<vector<ll>> mat;

    Matrix(){
        mat = vector<vector<ll>>(2, vector<ll>(2));
        mat[0][0] = mat[1][1] = 1;
    }



    Matrix operator*(Matrix other){
        Matrix ret;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                ret[i][j] = 0;
                for(int k=0;k<2;k++){
                    ret[i][j] += mat[i][k] * other[k][j] % MOD;
                    ret[i][j] %= MOD;
                }
            }
        }
        return ret;
    }

    vector<ll>& operator [](int idx){
        return mat[idx];
    }

};


ll f(ll n){//피보 n번째 항
    Matrix ret, a;
    a[0][0] = a[0][1] = a[1][0] = 1;
    a[1][1] = 0;

    n--;
    while(n){
        if(n%2==1) ret = ret*a;
        a = a*a;
        n /= 2;
    }

    return ret[0][0];
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n;cin>>n;
    if(n%2==0) n++;

    cout<<(f(n) - 1 + MOD) % MOD;
    return 0;
}