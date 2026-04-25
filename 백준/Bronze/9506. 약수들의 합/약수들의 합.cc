#include <stdio.h>
#include <vector>
using namespace std;
vector<int> vec;
int n;
int main(){

	scanf("%d", &n);
	
	while(n!=-1){
 	int sum=0;
		for(int i=1;i<n;i++){
			if(n%i==0) {
			vec.push_back(i);
			sum+=i;
			}
		}
		if(n==sum){
			printf("%d = 1", n);
			for(int i=1;i<vec.size();i++){
				printf(" + %d", vec[i]);
			}
		}
		else{
			printf("%d is NOT perfect.", n);
		} 
		printf("\n");
		vec.clear();
		scanf("%d", &n);
	}
	return 0;
} 