#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Position{
    int x1, x2;

    bool operator<(const Position&other)const{
        if(x1 == other.x1) return x2 > other.x2;
        return x2 >= other.x2;
    }
};
set<Position> seen;
vector<Position> pos;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        int a,x1,x2;cin>>a>>x1>>x2;
        if(seen.count({x1, x2})) continue; //완전히 겹침
        seen.insert({x1, x2});

        pos.push_back({x1, x2});
    }

    sort(pos.begin(), pos.end(), [](Position a, Position b){
        if(a.x1 == b.x1) return a.x2 > b.x2;
        return a.x1 < b.x1;
    });


    vector<Position> lis;
    for(int i=0;i<pos.size();i++){
        int idx = lower_bound(lis.begin(), lis.end(), pos[i]) - lis.begin();
        if(idx == lis.size()) lis.push_back(pos[i]);
        else lis[idx] = pos[i];
    }

    cout<<lis.size();
    return 0;
}