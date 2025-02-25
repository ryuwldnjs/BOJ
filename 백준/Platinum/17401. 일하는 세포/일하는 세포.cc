#include <iostream>
#include <vector>
#define MOD 1000000007
using namespace std;
using ll=long long;
struct Matrix{
    int size;
    vector<vector<ll>> mat;
    Matrix(int size) : size(size), mat(size, vector<ll>(size)){}
    
    void init(){
        for(int i=0;i<size;i++) mat[i][i] = 1;
    }
    Matrix operator*(const Matrix& other)const{
        Matrix tmp(size);
        for(int i=0;i<size;i++){
            for(int j=0;j<size;j++){
                for(int k=0;k<size;k++){
                    tmp[i][j] += ((*this)[i][k] * other[k][j]) % MOD;
                    tmp[i][j] %= MOD;
                }
            }
        }
        return tmp;
    }
    vector<ll>& operator[](int idx) {
        return mat[idx];
    }

    const vector<ll>& operator[](int idx) const {
        return mat[idx];
    }

};

Matrix makeMatrix(int size){
    Matrix tmp(size);
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c; cin>>a>>b>>c;
        a--; b--;
        tmp[a][b] = c;
    }
    return tmp;
}

Matrix pow(Matrix a, int x){
    Matrix tmp(a.size);
    tmp.init();
    while(x){
        if(x%2) tmp = tmp*a;
        a = a*a;
        x/=2; 
    }
    return tmp;
}
int main(){
    cin.tie(0); ios::sync_with_stdio(0);
    int t,n,d; cin>>t>>n>>d;

    int total_cnt = d / t;
    int remain_cnt = d % t;
    Matrix all(n), remain(n);
    all.init(); remain.init();
    for(int i=0;i<t;i++){
        all = all*makeMatrix(n);
        if(i == remain_cnt-1) remain = all;
    }

    Matrix answer = pow(all, total_cnt) * remain;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<answer[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}