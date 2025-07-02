#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,l,m;cin>>n>>l>>m;
    vector<pii> fish(m);
    vector<int> cand_y, cand_x;
    for(int i=0;i<m;i++){
        int a,b;cin>>a>>b;
        fish[i] = {a,b};
        cand_y.push_back(a);
        cand_x.push_back(b);
    }

    l /= 2;

    int answer = 0;

    for(int y: cand_y){
        for(int x: cand_x){
            for(int dy=1;dy<l;dy++){
                int dx = l - dy;

                int yy = y + dy;
                int xx = x + dx;
                int cnt = 0;

                for(int j=0;j<m;j++){
                    if(y <= fish[j].first && fish[j].first <= yy && x <= fish[j].second && fish[j].second <= xx) cnt++;
                }
                // printf("%d %d %d %d: %d\n",y,x,yy,xx,cnt);
                answer = max(answer, cnt);
            }
        }
    }

    cout<<answer;
    return 0;
}