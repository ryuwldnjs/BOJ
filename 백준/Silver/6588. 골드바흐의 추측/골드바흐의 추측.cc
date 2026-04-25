#include <iostream>
#include <vector> 
#define NUM 1000000
using namespace std;
vector<int> vec; //소수 저장 
int era[NUM+50];
int t,n;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	//에라토스테네스의 체 
	for(int i=2;i<=NUM;i++) era[i] = 1; 
	
	for(int i=2;i<=NUM;i++){
		if(era[i]){ //소수를 찾았을 때 
	//	vec.push_back(i);
			for(int j=i+i;j<=NUM;j+=i){
				era[j] = 0;
			}
		}
	}
	
	while(true){
		cin>>n;
		if(n==0) break;
		int flag=0;
		for(int i = 3;i<=n/2;i++){ // n = p + (n-p)를 이용 
			if(!era[i] || !era[n-i]) continue;
			cout<<n<<" = "<<i<<" + "<<n-i<<"\n";
			flag=1; //답이 존재 
			break;
		}
		if(flag==0) cout<<"Goldbach's conjecture is wrong.\n";
		
		
	}
	return 0;
}