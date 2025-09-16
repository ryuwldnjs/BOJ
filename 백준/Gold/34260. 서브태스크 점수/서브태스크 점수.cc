#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD = 998244353;

vector<ll> answer(5000); //
vector<ll> s;
vector<vector<ll>> graph;

ll n,m;

//필요한 태스크들 모음
vector<bool> visited;
int getTask(int now){
    int bit = (1<<now);
    visited[now] = true;
    for(int next: graph[now]){
        if(!visited[next]) bit |= getTask(next);
    }
    return bit;
}

//해당 조합으로 섭태 구성이 가능할떄
bool able(int bit){
    int needed = 0;
    visited = vector<bool>(n);
    for(int i=0;i<n;i++){
        if((1<<i) & bit) needed |= getTask(i);
    }

    if((needed & bit) == needed) return true;
    return false;
}

int getSum(int bit){
    int sum = 0;
    for(int i=0;i<n;i++){
        if((1<<i) & bit) sum += s[i]; 
    }
    return sum;
}

void solve(){
    cin>>n>>m;
    s = vector<ll>(n);
    graph = vector<vector<ll>>(n);

    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    for(int i=0;i<m;i++){
        ll x,y;cin>>x>>y;
        graph[y-1].push_back(x-1);
    }

    vector<ll> dp(5000);
    for(int bit=1;bit<(1<<n);bit++){
        if(able(bit)){
            dp[getSum(bit)]++;
        }
    }


    for(int i=3000;i>=0;i--){
        for(int j=0;j<=100;j++){
            if(i-j>=0) answer[i] += answer[i - j] * dp[j];
            answer[i] %= MOD;
        }
    }
}

int main(){
    cin.tie() -> sync_with_stdio(0);
    answer[0] = 1;
    int p;cin>>p;
    for(int i=0;i<p;i++) solve();


    ll ret = 0;
    for(int i=0;i<=p*100;i++){
        // cout<<i<<": "<<answer[i]<<'\n';
        ret += (answer[i] * i) % MOD;
        ret %= MOD;
    }
    cout<<ret;
    return 0;
}