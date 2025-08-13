#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n,m,t,k;
vector<int> y,x;

int getCnt(int x1, int y1){
    int ret = 0;
    int x2 = x1 + k;
    int y2 = y1 + k;
    
    for(int i=0;i<t;i++){
        if(x1<=x[i]&&x[i]<=x2 && y1<=y[i]&&y[i]<=y2){
            ret++;
        }
    }
    return ret;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>t>>k;
    x.resize(t);
    y.resize(t);
    for(int i=0;i<t;i++){
        cin>>x[i]>>y[i];
    }

    pii answer;
    int MAX = -1;
    for(int x: x){
        for(int y: y){
            // printf("%d %d\n", x,y);
            int cnt = getCnt(x, y);
            if(MAX < cnt){
                MAX = cnt;
                answer = {x, y};
            }
        }
    }


    answer.first = min(answer.first, n - k);
    answer.second = min(answer.second, m - k);

    cout<<answer.first<<' '<<answer.second + k<<'\n';
    cout<<MAX;
    return 0;
}