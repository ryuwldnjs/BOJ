#include <iostream>
#include <string>
#define INF 987654321
using namespace std;
int map[27][27];
int n;
char a,b;
string str;
int main(){
	cin>>n;
	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			if(i==j) map[i][j] = 0;
			else map[i][j] = INF;
		}
	}
	
	for(int i=0;i<n;i++){
		cin>>a>>str>>b;
		map[a - 'a'][b - 'a'] = 1;
	}

	//플로이드 
	for(int k=0;k<26;k++){
		for(int i=0;i<26;i++){
			for(int j=0;j<26;j++){
				if(map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}

	cin>>n;
	while(n--){
		cin>>a>>str>>b;
		if(map[a - 'a'][b - 'a'] == INF)
			cout<<"F\n";
		else
			cout<<"T\n";
	}
	return 0;
}