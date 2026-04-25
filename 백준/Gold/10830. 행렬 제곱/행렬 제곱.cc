#include <iostream>
#include <vector>
using namespace std;

class matrix{ //정사각행렬 
	int n; //행렬 길이 
public:
	vector<vector<int> > mat;//행렬을 나타낼  2차원배열 
	matrix(int n){ //생성자
		this->n = n; 
		mat.resize(n);
		for(int i=0;i<n;i++)
			mat[i].resize(n);
		
	}
	
	
	void print();
	void init();
	matrix operator*(const matrix& m);
};

void matrix::print(){
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<mat[i][j]<<' ';
		}
		cout<<'\n';
	}
}
void matrix::init(){
	for(int i=0;i<n;i++)
		mat[i][i] = 1;
}
matrix matrix::operator*(const matrix& m){
	matrix tmp(this->n);//임시 행렬 생성 
	
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				tmp.mat[i][j] += this->mat[i][k] * m.mat[k][j];
			}
			tmp.mat[i][j] %= 1000;
		}
	}
	return tmp;
}

matrix pow(matrix &A, long long b){
	if(b == 1) return A;
	
	matrix tmp = pow(A, b/2);
	
	if(b%2 == 0)
		return tmp*tmp;
	else
		return (tmp*tmp)*A; 
}

int main(){
	long long n,b;
	cin>>n>>b;
	
	matrix A(n); //n^2크기의 행렬 A생성  
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>A.mat[i][j];
			A.mat[i][j] %= 1000;
		}
	} 
	matrix ans = pow(A, b);
	
	ans.print();
	return 0;
}