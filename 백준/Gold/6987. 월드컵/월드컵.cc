#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int win,draw,lose;
    bool operator<(const Info& other)const{
        if(win==other.win && draw==other.draw) return lose > other.lose;
        if(win==other.win) return draw > other.draw;
        return win > other.win;
    }


    bool operator==(const Info& other)const{
        return win==other.win && draw==other.draw && lose==other.lose;
    }
};

vector<pii> games;

bool dfs(vector<Info> &a, int idx){
    if(idx == 15) return true;
    
    int ret = false;
    auto [i,j] = games[idx];
    if(a[i].win>0 && a[j].lose>0){
        a[i].win--; a[j].lose--;
        ret = ret || dfs(a, idx+1);
        a[i].win++; a[j].lose++;
    }


    if(a[i].lose>0 && a[j].win>0){
        a[i].lose--; a[j].win--;
        ret = ret || dfs(a, idx+1);
        a[i].lose++; a[j].win++;
    }

    if(a[i].draw>0 && a[j].draw>0){
        a[i].draw--; a[j].draw--;
        ret = ret || dfs(a, idx+1);
        a[i].draw++; a[j].draw++;
    }

    return ret;
}


void solve(){
    vector<Info> arr(6);
    bool ret = true;
    for(int i=0;i<6;i++){
        int a,b,c;cin>>a>>b>>c;
        arr[i] = {a,b,c};
        if(a+b+c != 5) ret = false;
    }
    // sort(arr.begin(), arr.end());

    cout<<(ret && dfs(arr,0))<<' ';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++) games.push_back({i,j});
    }

    int t=4; while(t--) solve();
    return 0;
}