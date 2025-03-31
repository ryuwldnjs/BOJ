#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;
using ll=long long;
struct Info{
    ll idx;
    ll water;
};
ll n;
void bfs(){
    if(n==0){
        cout<<"0 0";
        return;
    }
    queue<Info> q;
    vector<ll> water(n+1, INF);
    ll days = 0;
    q.push({0, 0});
    water[0] = 0;
    while(!q.empty()){
        ll sz = q.size();


        while(sz--){
            ll now = q.front().idx;
            ll now_water = q.front().water;
            q.pop();

            if(now+1 <= n && now_water+1 < water[now+1]){
                q.push({now+1, now_water+1});
                water[now+1] = now_water+1; 
            }
            if(now*3 <= n && now_water+3 < water[now*3]){
                q.push({now*3, now_water+3});
                water[now*3] = now_water+3;
            }
            if(now*now <= n && now_water+5 < water[now*now]){
                q.push({now*now, now_water+5});
                water[now*now] = now_water+5;
            }
        }
        days++;
        if(water[n] != INF){
            cout<<days<<' '<<water[n];
            return;
        }
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;

    bfs();
    return 0;
}