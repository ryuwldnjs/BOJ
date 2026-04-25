#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, int> clothes;
string str;
int ans, T,n;

//의상을 입지않은 것을 하나의 패션으로 간주하여 중복순열 계산 
//단, 모든 의상을 입지 않은 경우 1개를 제외해야함 
int main(){
	cin>>T;
	while(T--){
		clothes = map<string, int>();
		ans = 1;
		
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>str>>str;
			clothes[str]++;
		}
		
		for(map<string,int>::iterator it = clothes.begin(); it != clothes.end(); it++){
			ans *= it->second + 1;
		}
		
		cout<<ans-1<<'\n';
	}
	return 0;
}