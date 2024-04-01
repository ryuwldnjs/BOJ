#include <iostream>
#include <algorithm>
using namespace std;
int n,a,b;
int arr[100000+5], dp[6][100000+5];
int answer[6];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>b;
		arr[i] = (1<<a) | (1<<b);
	}
	
	for(int grade=1;grade<=5;grade++){
		for(int i=1;i<=n;i++){
			if(arr[i] & (1<<grade)){
				dp[grade][i] = dp[grade][i-1] + 1;
			}
			answer[grade] = max(answer[grade], dp[grade][i]);
		}
	}
	
	int ans_idx = max_element(answer+1, answer+6) - answer;
	cout<<answer[ans_idx]<<' '<<ans_idx;
	return 0;
}