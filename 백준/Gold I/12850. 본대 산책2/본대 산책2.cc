#include <bits/stdc++.h>
#define MOD 1'000'000'007
using namespace std; 
struct Matrix{
	int sz = 8;
	vector<vector<long long>> mat = {
		{0,1,1,0,0,0,0,0},
		{1,0,1,1,0,0,0,0},
		{1,1,0,1,1,0,0,0},
		{0,1,1,0,1,1,0,0},
		{0,0,1,1,0,1,0,1},
		{0,0,0,1,1,0,1,0},
		{0,0,0,0,0,1,0,1},
		{0,0,0,0,1,0,1,0}	
		};

	void init(int n){
		mat = vector<vector<long long>>(sz,vector<long long>(sz));
		for(int i=0;i<sz;i++) mat[i][i] = n;
	}
	
	Matrix operator*(Matrix& b){
		Matrix tmp;
		tmp.init(0);
		for(int i=0;i<sz;i++){
			for(int j=0;j<sz;j++){
				for(int k=0;k<sz;k++){
					tmp[i][j] = (tmp[i][j] + this->mat[i][k]*b[k][j]) % MOD;
				}
			}
		}
		return tmp;
	}
	vector<long long>& operator[](int a){
		return mat[a];
	}
};



int main(){
	int d;
	cin>>d;
	Matrix answer, tmp;
	answer.init(1);
	while(d){
		if(d%2) answer = answer*tmp;
		d >>= 1;
		tmp = tmp*tmp;
	}
	cout<<answer[0][0];
	return 0;
}