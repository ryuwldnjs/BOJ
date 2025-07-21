#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define NOT_MATCH 1000
struct Info{
    ll y,x;
};
ll dist2(Info a, Info b){
    return (a.y-b.y)*(a.y-b.y) + (a.x-b.x)*(a.x-b.x);
}
vector<int> match;
// void choice(int idx, int matching){
//     if(matching == n/2){

//     }


//     for(int i=0;i<n;i++){
//         if(idx == i) continue;
//         if(match[i] != NOT_MATCH) continue;
//         match[idx] = i;
//         match[i] = idx;

//         choice(idx + 1, matching+1);

//         match[idx] = NOT_MATCH;
//         match[i] = NOT_MATCH;
//     }
// }
int n;
vector<Info> p;

ll getTotal(){
    ll dy=0;
    ll dx=0;
    for(int i=0;i<n;i+=2){
        dy += p[i].y - p[i+1].y;
        dx += p[i].x - p[i+1].x;
    }
    return dy*dy + dx*dx;
}

void solve(){
    cin>>n;
    p = vector<Info>(n);

    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        p[i] = {a,b};
    }

    ll answer=(ll)1e15;
    for(int i=0;i<1000000;i++){
        int a = rand() % n;
        int b = rand() % n;
        swap(p[a], p[b]);
        ll ret = getTotal();
        if(ret < answer) answer = ret;
        // else swap(p[a], p[b]);
        // printf("%d\n", answer);
    }
    
    cout << fixed << setprecision(10) << sqrt(answer) << '\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    srand(2341113);
    int t; cin>>t; while(t--) solve();
    return 0;
}