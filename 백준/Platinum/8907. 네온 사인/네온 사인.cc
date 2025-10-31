#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

void solve(){
    int n;cin>>n;
    int answer = n*(n-1)*(n-2)/6;
    int red[1005]={}, blue[1005]={};

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int color;cin>>color;
            if(color==1){
                red[i]++;
                red[j]++;
            }
            else{
                blue[i]++;
                blue[j]++;
            }
        }
    }

    int biColor=0;
    for(int i=0;i<n;i++){
        biColor += blue[i] * red[i]; //i정점의 이색각의 개수
    }
    biColor /= 2; //이색각이 항상 쌍으로 존재하기 때문에, 이색삼각형의 개수는 그의 절반
    answer -= biColor;

    cout<<answer<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}