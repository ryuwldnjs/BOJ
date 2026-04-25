#include<stdio.h>
int main()
{
    int n,t;
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        t= n-i;
        for(int j=0;j<t;j++)
            printf(" ");
        for(int k=0;k<2*i-1;k++)
            printf("*");
        printf("\n");
    }

    for(int i=1;i<n;i++)
    {
        t=n-i;
        for(int j=0;j<i;j++)
            printf(" ");
        for(int k=0;k<2*t-1;k++)
            printf("*");
        printf("\n");
    }
    return 0;
}