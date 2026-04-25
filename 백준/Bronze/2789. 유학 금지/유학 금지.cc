#include <stdio.h>
char str[105];
int flag;
char cambridge[11]="CAMBRIDGE";
int main(){
	scanf("%s", str);
	
	for(int i=0;str[i];i++){
		flag=0;
		for(int j=0;cambridge[j];j++){
			if(str[i]==cambridge[j]){//같은단어 찾을때 
				flag=1;
				break;
			}
		}
		if(flag==0) printf("%c", str[i]); 
	}
	return 0;
}