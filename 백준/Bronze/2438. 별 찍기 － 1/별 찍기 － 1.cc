#include <stdio.h>
int n;
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++)
    {
        
        for(int j=0;j<i;j++)
        {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}