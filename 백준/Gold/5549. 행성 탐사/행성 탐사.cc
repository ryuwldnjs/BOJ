#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int J[1005][1005], I[1005][1005], O[1005][1005];
int n,m,k;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>m>>n;
    cin>>k;

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            char c; cin>>c;
            if(c == 'J') J[i][j]++;
            if(c == 'I') I[i][j]++;
            if(c == 'O') O[i][j]++;
            J[i][j] += J[i-1][j] + J[i][j-1] - J[i-1][j-1];
            I[i][j] += I[i-1][j] + I[i][j-1] - I[i-1][j-1];
            O[i][j] += O[i-1][j] + O[i][j-1] - O[i-1][j-1];
        }
    }

    while(k--){
        int y1,x1,y2,x2; cin>>y1>>x1>>y2>>x2;
        int psumJ = J[y2][x2] - J[y1-1][x2] - J[y2][x1-1] + J[y1-1][x1-1];
        int psumI = I[y2][x2] - I[y1-1][x2] - I[y2][x1-1] + I[y1-1][x1-1];
        int psumO = O[y2][x2] - O[y1-1][x2] - O[y2][x1-1] + O[y1-1][x1-1];

        cout<<psumJ<<' '<<psumO<<' '<<psumI<<'\n';
    }
    return 0;
}