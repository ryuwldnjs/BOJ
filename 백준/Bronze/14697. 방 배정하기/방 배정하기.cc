#include <stdio.h>

int main() 
{ 
    int n, a, b, c; 
    int i, j=0, k=0; 

    scanf("%d %d %d", &a, &b, &c); 
    scanf("%d", &n); 

    for(i=0 ; i<=n ; i+=a){ 
        for(j=i ; j<=n ; j+=b){ 
            for(k=j ; k<=n ; k+=c){ 
                if(k==n){ 
                    printf("1"); 
                    return 0; 
                } 
            } 
        } 
    } 
    printf("0"); 
    return 0; 
}
