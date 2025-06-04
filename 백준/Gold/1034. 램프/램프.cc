#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m,k;cin>>n>>m;
    vector<string> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cin>>k;

    sort(arr.begin(), arr.end());
    
    arr.insert(arr.begin(), "");
    arr.push_back("");

    int answer = 0;
    int cnt = 0;
    for(int i=1;i<=n+1;i++){
        if(arr[i] != arr[i-1]){
            int cost = count(arr[i-1].begin(), arr[i-1].end(), '0');
            if(cost <= k && (k - cost) % 2 == 0){
                answer = max(answer, cnt);
            }
            cnt = 1;
        }
        else cnt++;
    }
    cout<<answer;
    return 0;
}