#include <iostream>
#include <algorithm>
using namespace std;
bool counting_sort[2000+50]; //계수정렬 - 시간복잡도 O(n)
int n,m;
int main(){
	cin.tie(NULL);
	ios::sync_with_stdio(true);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m;
		counting_sort[m+1000] = true;
	}
	
	for(int i=0;i<=2000;i++){ // -1000 ~ 1000이므로, 모든 숫자에 1000씩 더해줌 
		if(counting_sort[i]) cout<<i-1000<<" ";
	}
	return 0;
} 