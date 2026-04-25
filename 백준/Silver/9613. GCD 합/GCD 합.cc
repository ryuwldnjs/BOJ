#include <iostream>
using namespace std;
long long t,n, arr[105],sum;

int gcd(int a,int b){ //유클리드 
	return a%b==0 ? b : gcd(b,a%b);
}


int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>t;
	while(t--){
		cin>>n;
		sum=0; //매 테스트케이스마다 초기화 
		
		for(int i=0;i<n;i++){
			cin>>arr[i];
			for(int j=0;j<i;j++){
				sum += gcd(arr[i],arr[j]);
			}
		}
		
		cout<<sum<<"\n";
	}
	return 0;
} 