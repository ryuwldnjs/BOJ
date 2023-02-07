#include <iostream>
#include <string>
#include <vector>

using namespace std;
char pre = 'O';
vector<int> len;
int n,m,cnt,ans, flag;
string str;
int main(){
	cin>>n>>m>>str;
	for(int i=0;i<m;i++){ //IOI 문자열 찾기 
		if(str[i] == 'I') flag = 1;
		if(!flag) continue;
		
		if(pre != str[i]) cnt++;
		else{
			if(str[i] == 'O') cnt--;
			if(cnt>=3) len.push_back(cnt);
			cnt = str[i]=='I' ? 1 : 0;
		//	flag = 0;
		}
		
		pre = str[i];
	}
	
	
	if(cnt>=3) {
		if(str[m-1] == 'O') cnt--; // OIOIO
		len.push_back(cnt);
	}
	
	int p = 1 + 2*n;
	
	for(int i=0;i<len.size();i++){
	//	printf("%d\n", len[i]);
		int tmp = 1 + (len[i]-p) / 2;
		ans += tmp > 0 ? tmp : 0;
	}
	cout<<ans;
	return 0;
}