#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll MOD = 1'000'000'007;

struct Matrix{
    vector<vector<ll>> mat;
    int size;
    Matrix(int n){
        size = n;
        mat.resize(n, vector<ll>(size));
    }

    void init(){
        for(int i=0;i<size;i++) mat[i][i] = 1;
    }

    void build(){
        mat[0][0] = 4;
        mat[0][1] = MOD - 1;
        mat[1][0] = 1;
        mat[1][1] = 0;
    }
    Matrix operator*(const Matrix& other)const{
        Matrix ret(size);

        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){

                for(int k=0;k<size;k++){
                    ret.mat[i][j] += mat[i][k] * other.mat[k][j];
                    ret.mat[i][j] %= MOD;
                }
            }
        }
        return ret;
    }

};

Matrix mat(2), ret(2);
//dp[i] = 4dp[i-2] - dp[i-4];
void pow(ll x){
    ret.init();
    mat.build();
    while(x){
        if(x%2) ret = ret * mat;
        mat = mat * mat;
        x /= 2;
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n;cin>>n;
    if(n%2==1){
        cout<<0;
        return 0;
    }
    if(n == 0){
        cout<<1;
        return 0;
    }
    if(n == 2){
        cout<<3;
        return 0;
    }

    pow(n/2 - 1);
    
    ll answer = (ret.mat[0][0] * 3 + ret.mat[0][1]) % MOD;
    cout<<answer;
    return 0;
}