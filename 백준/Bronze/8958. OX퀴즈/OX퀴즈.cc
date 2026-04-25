#include <stdio.h>
int main()
{
int N,i,j;
scanf("%d",&N);
char quiz[N][80]={};
for(i=0;i<N;i++)
{
int count=0,sum=0,score=0;
scanf("%s",quiz[i]);
for(j=0;j<79;j++)
{
if(quiz[i][j]=='O')
{
count+=1;
sum+=count;
}
if(quiz[i][j]=='X') count=0;
}
printf("%d\n",sum);
}


}