#include <iostream>
using namespace std;
int arr[2005], dp[2005][2005];
int n,m,a,b;

int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	
	//팰린드롬 구간 [a,b]에 대한 판정 
	for(int i=1;i<=n;i++){
		int gap=0;
		while(i - gap >= 1 && i + gap <= n){
			if(arr[i-gap]==arr[i+gap])
				dp[i-gap][i+gap] = 1;
			else
				break;
			
			gap++; 
		}
	}
	
	//중앙이 두개일때 
	for(int i=1;i<n;i++){
		int gap=0;
		while(i - gap >= 1 && i + gap + 1 <= n){
			if(arr[i-gap]==arr[i+gap+1])
				dp[i-gap][i+gap+1] = 1;
			else
				break;
			
			gap++; 
		}
	}
	
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		cout<<dp[a][b]<<'\n';
	}
	return 0;
}