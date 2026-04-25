#include <stdio.h>
char file[55], name[55];
int n;
int main(){
	scanf("%d", &n);
	
	scanf("%s", file);
	for(int i=0;i<n-1;i++){
		scanf("%s", name);
		
		for(int j=0;file[j];j++){
			if(file[j]!=name[j]){
				file[j]='?';
			}
		}
	}
	printf("%s", file);
	return 0;
}