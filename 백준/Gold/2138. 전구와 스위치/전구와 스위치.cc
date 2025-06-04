#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
int getAnswer(vector<int> input, vector<int>&goal){
    int ret = 0;
    for(int i=0;i<input.size()-2;i++){
        if(input[i] != goal[i]){
            input[i] = !input[i];
            input[i+1] = !input[i+1];
            input[i+2] = !input[i+2];
            ret++;
        }
    }
    if(input != goal) return INF;
    return ret;
}
void solve(){
    int n;cin>>n;
    vector<int> input(n), goal(n);
    for(int i=0;i<n;i++){
        char c; cin>>c;
        input[i] = c - '0';
    }
    for(int i=0;i<n;i++){
        char c; cin>>c;
        goal[i] = c - '0';
    }

    int answer = INF;
    answer = min(answer, getAnswer(input, goal));
    input[0] = !input[0];
    input[1] = !input[1];
    answer = min(answer, getAnswer(input, goal) + 1);
    input[n-1] = !input[n-1];
    input[n-2] = !input[n-2];
    answer = min(answer, getAnswer(input, goal) + 2);
    input[0] = !input[0];
    input[1] = !input[1];
    answer = min(answer, getAnswer(input, goal) + 1);
    if(answer == INF) cout<<-1;
    else cout<<answer;
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t=1; while(t--) solve();
    return 0;
}