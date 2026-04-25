#include <stdio.h>
int ans,n,student,apple;
int main(){
	scanf("%d", &n);
	
	for(int i=0;i<n;i++){
		scanf("%d %d", &student, &apple);
		ans += apple%student;
	}
	printf("%d", ans);
	return 0;
}