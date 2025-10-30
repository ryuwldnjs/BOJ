#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll MOD = 1000000007;

struct Matrix{
    vector<vector<ll>> mat;

    Matrix(){
        mat.resize(2, vector<ll>(2));
    }

    void init(){//단위행렬
        mat[0][0] = mat[1][1] = 1;
    }
    void init_fibo(){
        mat[0][0] = mat[0][1] = mat[1][0] = 1;
    }


    Matrix operator*( Matrix& other)const{
        Matrix ret;

        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                for(int k=0;k<2;k++){
                    ret[i][j] += mat[i][k] * other[k][j];
                    ret[i][j] %= MOD;
                }
            }
        }
        return ret;
    }

    vector<ll> &operator[](const int idx){
        return mat[idx];
    }
};

Matrix pow(Matrix a, ll x){
    Matrix ret;
    ret.init();
    while(x){
        if(x%2) ret = ret*a;
        a = a*a;
        x/=2;
    }
    return ret;
}


ll fibo(ll n){
    Matrix fiboMat;
    fiboMat.init_fibo();

    Matrix ret = pow(fiboMat, n-1);
    return ret[0][0];
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n;cin>>n;
    cout<<fibo(n) * fibo(n+1) % MOD;
    return 0;
}