#include <stdio.h>
int a,b,c; //숭,고,한 
int main(){
	scanf("%d %d %d", &a, &b ,&c);
	
	if(a+b+c>=100) printf("OK");
	else{
		if(a<b&&a<c) printf("Soongsil");
		if(b<a&&b<c) printf("Korea");
		if(c<a&&c<b) printf("Hanyang");
	}
	return 0;
}