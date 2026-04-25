#include <stdio.h>
int t;
char str[55];
int main(){
	scanf("%d", &t);
	while(t--){
		int open=0,close=0;
		bool flag=false;
		scanf(" %s", str);
		
		for(int i=0;str[i];i++){
			if(str[i]=='(') open++;
			else close++;
			if(close>open) flag=true;
		}
		if(flag|| open!=close) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}