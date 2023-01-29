#include <iostream>
#include <deque>
#include <string> 
using namespace std;

int T,n, num, sign=1;
deque<int> dq;
string cmd, arr;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>T;
	while(T--){
		cin>>cmd>>n>>arr;
		dq = deque<int>(); //초기화 
		sign = 1;
		num = 0;
		
		
		//문자열입력을 덱에 넣기 
		int sz = arr.size(); 
		for(int i=1;i<sz; i++){
			if(isdigit(arr[i])){
				num *= 10;
				num += arr[i] - '0';
			}
			else{ //콤마	 
				if(i!=1) dq.push_back(num);
				num = 0;		
			}	
		}
		sz = cmd.size();
		for(int i=0; i<sz; i++){
			if(cmd[i] == 'R') sign ^= 1; //리버스 토글링 
			else if(!dq.empty()){
				if(sign) dq.pop_front();
				else dq.pop_back();
			}
			else{ //에러 발생 
				cout<<"error\n";
				goto ILoveHaeundae;
			}
		}
		
		//빈 배열 입력일때  
		if(dq.size() == 0) {
			cout<<"[]\n";
			continue;
		}
		//출력부 
		if(sign){
			cout<<"["<<dq.front();
			for(auto it = ++dq.begin(); it!= dq.end(); it++){
				cout<<","<<*it;
			}
			cout<<"]\n";
		}
		else{
			cout<<"["<<dq.back();
			for(auto it = ++dq.rbegin(); it != dq.rend(); it++){
				cout<<","<<*it;
			}
			cout<<"]\n";
		}
		
		
		ILoveHaeundae :;
	}
	return 0;
}