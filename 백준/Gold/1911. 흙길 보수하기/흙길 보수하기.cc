#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii=pair<int,int>;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,l; cin>>n>>l;
    vector<pii> arr(n);;
    for(int i=0;i<n;i++){
        cin>>arr[i].first>>arr[i].second;
    }
    sort(arr.begin(), arr.end());

    int last = -1;
    int answer = 0;
    for(int i=0;i<n;i++){
        int start = max(last, arr[i].first);
        int end = arr[i].second;
        if(start >= end) continue;

        int cnt = (end - start + l-1) / l;
        answer += cnt;
        last = start + cnt*l;
    }
    cout<<answer;
    return 0;
}