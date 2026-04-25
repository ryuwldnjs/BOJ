#include <stdio.h>
char word[20];
char alpha[9][5]={"ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", "TUV", "WXYZ"};
int time;
int main(){
	scanf("%s", word);
//	printf("%s", alpha[1]);
	for(int i=0;word[i];i++){
		for(int j=0;j<8;j++){
			for(int k=0;alpha[j][k];k++){
				if(word[i]==alpha[j][k]){
				time+= j+3;	
				goto end;
				}
			}
		}
		end:;
	}
	printf("%d", time);
	return 0;
}