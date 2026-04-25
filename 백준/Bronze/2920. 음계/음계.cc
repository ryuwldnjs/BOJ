#include <stdio.h>
int arr[8];
bool flag_p=false;
bool flag_m=false;

int main(){
	
	for(int i=0;i<8;i++){
		scanf("%d", &arr[i]);
	}
	
	for(int i=0;i<8;i++){
		if(arr[i]!=i+1) //증가가 아닐때
		{
			flag_p=true;
			break;
		 } 
	}
	
	if(flag_p) //증가가 아닐때
	{
		for(int i=0;i<8;i++){
			if(arr[i]!=8-i) //증가가 아닐때
		{
			flag_m=true;
			break;
		 } 
		}
	 } 
	 
	 if(flag_p&&flag_m){ //증가 감소 둘다 아닐떄 
	 	printf("mixed");
	 }
	 else if(flag_p){
	 	printf("descending");
	 }
	 else
	 	printf("ascending");
	 
	return 0;
}