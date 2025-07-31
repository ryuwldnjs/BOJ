#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll MOD = 1'000'000'007;
struct Matrix{
    vector<vector<ll>> mat;

    Matrix(){
        mat = vector<vector<ll>>(2, vector<ll>(2));
    }
    void init(){
        mat[0][0] = 1; mat[0][1] = 0;
        mat[1][0] = 0; mat[1][1] = 1;
        
    }
    void setFibo(){
        mat[0][0] = 1; mat[0][1] = 1;
        mat[1][0] = 1; mat[1][1] = 0;
    }

    vector<ll> &operator[](int idx){
        return mat[idx];
    }

    Matrix operator*(Matrix other){
        Matrix ret;
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    ret[i][j] += mat[i][k] * other[k][j];
                    ret[i][j] %= MOD;

                }
            }
        }

        // printf("%d %d\n%d %d\n\n",ret[0][0],ret[0][1],ret[1][0],ret[1][1]);
        return ret;
    }
};

Matrix power(ll x){
    Matrix a, ret;
    a.setFibo();
    ret.init();

    while(x){
        if(x % 2) ret = ret * a;
        a = a * a;
        x /= 2;
    }
    return ret;
}

// f[x]
ll fibo(ll x){
    if(x <= 1) return x;
    Matrix a = power(x-1);
    // cout<<a[0][0]<<'\n';
    return a[0][0];
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n,m;cin>>n>>m;
    if(n > m) swap(n, m);
    if(n == 0){
        cout<<0;
        return 0;
    }
    
    ll GCD = gcd(n,m);

    cout<<fibo(GCD);

    return 0;
}