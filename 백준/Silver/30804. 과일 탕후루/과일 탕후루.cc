#include <iostream>
using namespace std;
int n, arr[200000+5];
int fruit[10], type;
int MAX=1;
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int l=0,r=1;
	fruit[arr[l]]++;
	type++;
	while(r != n){
		if(fruit[arr[r]]==0 && type < 2){
			fruit[arr[r]]++;
			type++;
			r++;
		}
		else if(fruit[arr[r]] > 0){
			fruit[arr[r]]++;
			r++;
		}
		else{
			if(--fruit[arr[l]] == 0) type--;
			l++;
		}
		MAX = max(MAX, r-l);
	}
	cout<<MAX;
	return 0;
}