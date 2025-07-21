#include <bits/stdc++.h>
using namespace std;
using ll=long long;
struct Info{ll y,x;}p[20];
int n;
ll g(){
    ll y=0,x=0;
    for(int i=0;i<n;i+=2)y+=p[i].y-p[i+1].y,x+=p[i].x-p[i+1].x;
    return y*y+x*x;
}
int main(){
    int t; cin>>t; while(t--){
        cin>>n;
        for(int i=0;i<n;i++)scanf("%lld %lld",&p[i].y,&p[i].x);
        ll a=(ll)1e15;
        for(int i=0;i<1e6;i++){
            int x=rand()%n, y=rand()%n;
            swap(p[x], p[y]);
            a=min(a,g());
        }
        printf("%.9lf\n",sqrt(a));
    }
    return 0;
}