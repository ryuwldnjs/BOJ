#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    vector<int> arr(n*2+1), psum(n*2+1);
    int total = 0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        arr[i+n] = arr[i];
        total += arr[i];
    }
    for(int i=1;i<=n*2;i++){
        psum[i] = psum[i-1] + arr[i];
    }

    int answer = 0;
    for(int r=1;r<=n*2;r++){
        int l = lower_bound(psum.begin(), psum.end(), psum[r] - total/2) - psum.begin();
        answer = max(answer, psum[r] - psum[l]);
    }
    cout<<answer;
    return 0;
}