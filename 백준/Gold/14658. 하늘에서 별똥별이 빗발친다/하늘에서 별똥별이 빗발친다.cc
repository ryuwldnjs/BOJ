#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<pii> a, pos;
int n,m,l,k;

int getStars(int x1, int y1, int x2, int y2){
    int cnt = 0;
    for(auto [x,y] : a){
        if(x1<=x&&x<=x2 && y1<=y&&y<=y2) cnt++;
    }
    return cnt;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>m>>l>>k;
    a.resize(k);

    for(int i=0;i<k;i++) cin>>a[i].first>>a[i].second;
    for(int i=0;i<k;i++){
        for(int j=0;j<k;j++){
            pos.push_back({a[i].first, a[j].second});
        }
    }

    int answer = k;
    //[x,y]를 시작으로 트램펄린을 둘떄
    for(auto [x,y]: pos){
        answer = min(answer, k - getStars(x, y, x+l, y+l));
        // printf("[%d,%d]: %d개\n", x,y, getStars(x, y, x+l, y+l));
    }

    cout<<answer;
    return 0;
}