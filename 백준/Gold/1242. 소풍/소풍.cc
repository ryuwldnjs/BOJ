#include <iostream>
using namespace std;

int main(){
	int n,k,m,cnt=0;
	cin>>n>>k>>m;
	
	while(true){
		cnt++;
		//printf("cnt:%d, m:%d n:%d\n", cnt, m, n);
		
		if(m == (k-1)%n+1) break;//동호가 걸렸다! 
		
	//	m = (n + m - k -1)%n + 1;
		m = (m-k-1)%n+1;
		if(m<=0) m+=n;
		//동호의 위치를 옮겨줌 
		n--;//한명씩 퇴장 
	}
	cout<<cnt;
	return 0;
}