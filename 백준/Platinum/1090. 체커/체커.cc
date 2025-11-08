#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Position{
    int x,y;
};
vector<Position> pos;
int n;
int x[55], y[55];
vector<int> answer(55, 1e9);

//p를 최적의 장소라 했을때, 1~n개의 체커들의 최소 이동거리
void solve(Position p){
    vector<int> cost;//p와 체커들이 거리들
    for(int i=0;i<n;i++){
        int dist = abs(x[i] - p.x) + abs(y[i] - p.y);
        cost.push_back(dist);
    }
    sort(cost.begin(), cost.end());

    int sum = 0;
    for(int i=0;i<n;i++){
        sum += cost[i];
        answer[i] = min(answer[i], sum);
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            pos.push_back({x[i], y[j]});
        }
    }


    //p를 최적이라 가정하고, 1~n개의 체커를 뭉치게 하는 (누적)최소 거리 계산
    for(auto p : pos){
        solve(p);
    }

    for(int i=0;i<n;i++) cout<<answer[i]<<' ';
    return 0;
}