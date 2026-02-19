#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<ll,ll>;
using pll=pair<ll,ll>;
struct Info{
    ll prev;
    char op;
};

ll s,t;

bool pass(ll num){
    return 1<=num && num <=1e9;
}

void bfs(){
    if(s == t){
        cout<<0;
        return;
    }

    queue<pii> q;
    map<ll, Info> prev;
    
    prev[s] = {-1, -1};
    q.push({s, 0});

    while(!q.empty()){
        auto [now, cost] = q.front();
        q.pop();
        if(now == t){
            string answer;
            do{
                answer += prev[now].op;
                now = prev[now].prev;
            }while(prev[now].prev != -1);
            reverse(answer.begin(), answer.end());

            cout<<answer;
            return;
        }

        vector<ll> nexts = {now*now, now*2, 1};
        string ops = "*+/";
        for(ll i=0;i<3;i++){
            ll next = nexts[i];
            char op = ops[i];

            if(!pass(next)) continue;
            if(prev.count(next) == 0){
                prev[next] = {now, op};
                q.push({next, cost + 1});
            }
        }
    }
    cout<<-1;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>s>>t;

    bfs();

    return 0;
}