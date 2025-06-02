#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<int> multitap, arr;
bool existTarget(int target){
    for(int i=0;i<multitap.size();i++){
        if(multitap[i] == target) return true;
    }
    return false;
}

bool pushTarget(int target){
    for(int i=0;i<multitap.size();i++){
        if(multitap[i] == 0){
            multitap[i] = target;
            return true;
        }
    }
    return false;
}

void OPT(int idx){
    int target = arr[idx];
    int MAX = -1;
    for(int i=0;i<multitap.size();i++){
        int num = multitap[i];
        int j;
        for(j=idx+1;j<arr.size();j++){
            if(arr[j] == num){
                MAX = max(MAX, j);
                break;
            }
        }

        if(j == arr.size()){//앞으로 등장하지 않음
            multitap[i] = target;
            return;
        }

    }


    for(int i=0;i<multitap.size();i++){
        if(multitap[i] == arr[MAX]){
            multitap[i] = target;
            return;
        }
    }

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,k;cin>>n>>k;
    multitap.resize(n);
    arr.resize(k);
    for(int i=0;i<k;i++){
        cin>>arr[i];
    }

    int answer = 0;
    for(int i=0;i<k;i++){
        // for(int i:multitap) cout<<i<<' ';
        // cout<<'\n';
        if(existTarget(arr[i])) continue;
        if(pushTarget(arr[i])) continue;
        OPT(i);
        answer++;
    }
    
    cout<<answer;
    return 0;
}