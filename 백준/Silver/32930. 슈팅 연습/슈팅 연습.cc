#include <iostream>
#include <vector>
using namespace std;
using pii=pair<int,int>;
int now_x, now_y, ans;
int n,m;
vector<pii> target;
vector<bool> isUsed(205);
int dist2(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}
void shot(){
    int MAX=0;
    int MAX_idx = 0;
    for(int i=0;i<target.size();i++){
        if(isUsed[i]) continue;
        int distance = dist2(now_x, now_y, target[i].first, target[i].second);
        if(distance > MAX){
            MAX = distance;
            MAX_idx = i;
        }
    }
    ans += MAX;
    isUsed[MAX_idx] = true;
    now_x = target[MAX_idx].first;
    now_y = target[MAX_idx].second;
}

int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        int x,y; cin>>x>>y;
        target.push_back({x,y});
    }
    for(int i=0;i<m;i++){
        shot();
        int x,y; cin>>x>>y;
        target.push_back({x,y});
    }
    cout<<ans;
    return 0;
}