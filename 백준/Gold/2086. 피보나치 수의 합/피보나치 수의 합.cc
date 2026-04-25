#include <iostream>
#include <vector>
#define MOD 1000000000
using namespace std;

class matrix{ //정사각행렬 
	int n; //행렬 길이 
public:
	vector<vector<long long> > mat;//행렬을 나타낼  2차원배열 
	matrix(int n){ //생성자
		this->n = n; 
		mat.resize(n);
		for(int i=0;i<n;i++)
			mat[i].resize(n);
	}
	
	void print(); //행렬 원소 출력 
	void init(); //단위행렬 생성 
	matrix operator*(const matrix& m); //행렬곱셈 오버로딩 
};

void matrix::init(){
	for(int i=0;i<n;i++){
		mat[i][i] = 1;
	}
}
void matrix::print(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<' ';
		}
		cout<<'\n';
	}
}

matrix matrix::operator*(const matrix& m){
	matrix tmp(this->n);//임시 행렬tmp 생성 
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				tmp.mat[i][j] += this->mat[i][k] * m.mat[k][j];
				
			}
			tmp.mat[i][j] %= MOD;
		}
	}
	return tmp;//두 행렬곱 결과 반환 
}

//빠른 거듭제곱 
matrix pow(matrix &A, long long b){
	matrix tmp(3);
	tmp.init();
	if(b == 0) return tmp; // 단위행렬 
	if(b == 1) return A;
	
	tmp = pow(A, b/2); //Divide - Conquer
	
	if(b%2 == 0)
		return tmp*tmp;
	else
		return (tmp*tmp)*A; 
}


int main(){
	long long a,b;
	matrix A(3);
	
	cin>>a>>b;
	A.mat[0][0]	= A.mat[0][1] = A.mat[0][2] = A.mat[1][0] = A.mat[2][2] = 1;
	
	matrix tmp_a = pow(A, a-1);
	matrix tmp_b = pow(A, b);
//	tmp_a.print();
//	tmp_b.print(); 
	int answer = (MOD + tmp_b.mat[1][0]+tmp_b.mat[1][2] - tmp_a.mat[1][0] - tmp_a.mat[1][2])%MOD;
	cout<<answer;
	return 0;
}