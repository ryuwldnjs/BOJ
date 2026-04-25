#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
char num[100000+10];
int sum;
bool flag;
bool compare(int a,int b){
	return a>b;
	}
int main()
{
	scanf("%s", num);
	for(int i=0;num[i]!=0;i++)
	{
		sum += num[i]-'0';
		if (num[i]=='0')
			flag=true;
	}
	
	sort(num, num+strlen(num), compare);
	
	if(sum%3==0&&flag) //3의 배수 and 0존재
		printf("%s",num);
	else
		printf("-1"); 
	return 0;
}