#include <iostream>
#include <vector>
#define MOD 1000003
using namespace std;
using ll = long long;
struct Matrix{
    int size;
    vector<vector<ll>> mat;
    Matrix(int n):size(n){
        mat.resize(n,vector<ll>(n,0));
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
    vector<ll>& operator[](int idx){
        return mat[idx];
    }
    const vector<ll>& operator[](int idx)const {
        return mat[idx];
    }
};

Matrix pow(Matrix a, int x){
    Matrix res(a.size);
    for(int i=0;i<a.size;i++) res[i][i] = 1;
    while(x){
        if(x%2) res = res * a;
        a = a * a;
        x /= 2; 
    }
    return res;
}

Matrix mat(50);
int main() {
    cin.tie(0); cout.tie(0); ios::sync_with_stdio(0);
    int n,s,e,t; cin>>n>>s>>e>>t;
    s--; e--;

    for(int i=0;i<n;i++){ 
        //i노드를 들어오기위한 관문 4개 설치, 4 -> 3-> 2 -> 1 -> 0
        for(int j=3;j>=0;j--) mat[5*i + j+1][5*i + j] = 1;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char c; cin>>c;
            int x = c - '0';
            if(x == 0) continue;
            int start_idx = i*5;
            int end_idx = j*5;
            // 거리가 x라면, 관문 x-1개를 거쳐서 목표지점으로 도착함
            mat[start_idx][end_idx + x - 1] = 1;
        }
    }


    Matrix answer = pow(mat,t);
    cout<<answer[5*s][5*e];

    return 0;
}