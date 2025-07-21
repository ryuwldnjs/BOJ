#include <bits/stdc++.h>
using namespace std;
using L=long long;
using I=int;
I t,n; 
struct Info{L y,x;}p[20];
L g(){
    L y=0,x=0;
    for(I i=0;i<n;i+=2)y+=p[i].y-p[i+1].y,x+=p[i].x-p[i+1].x;
    return y*y+x*x;
}
I main(){
    cin>>t; while(t--){
        cin>>n;
        for(I i=0;i<n;i++) cin>>p[i].y>>p[i].x;
        L a=(L)1e15;
        for(I i=0;i<1e6;i++){
            I x=rand()%n, y=rand()%n;
            swap(p[x], p[y]);
            a=min(a,g());
        }
        printf("%.9lf\n",sqrt(a));
    }
    return 0;
}