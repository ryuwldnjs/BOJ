#include <iostream>
#include <algorithm>
#define INF 1e9;
using namespace std;

int n;
int xl,yl, xr,yr;
int main(){
    xl = yl = INF;
    xr = yr = -INF;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        xl = min(xl, a);
        // x1 = min(x1, c);
        yl = min(yl, b);
        xr = max(xr, c);
        yr = max(yr, d);

        cout<<2*(xr-xl + yr-yl)<<'\n';
    }
    return 0;
}