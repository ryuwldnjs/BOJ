#include <iostream>
#include <vector>
#define INF 1e9
using namespace std;
using ll=long long;
int n;
vector<ll> arr;
ll dp[1005][1005][3];
bool visited[1005][1005][3];

//현재 idx번째 노트, combo콤보가 쌓여있고, miss번 실패했을때
ll solve(int idx, int combo, int miss){
    if(idx == n) return 0;
    ll &ret = dp[idx][combo][miss];
    if(visited[idx][combo][miss]) return ret;
    visited[idx][combo][miss] = true;

    
    //idx번째 노트를히트했을때
    ret = solve(idx+1, combo+1, 0) + arr[idx] * (combo+1);

    //idx번째 노트를 실패했을때 (단, 최근에 1번이하로 실패했어야 이번에도 실패할 기회가 있음)
    if(miss <= 1) ret = max(ret, solve(idx+1, 0, miss+1));
    
    return ret;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    arr.resize(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<max(0LL, solve(0, 0, 0));
    return 0;
}