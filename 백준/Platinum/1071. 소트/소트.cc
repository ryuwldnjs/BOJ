#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    vector<int> cnt(1000+5), answer;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        cnt[x]++;
    }

    int remain = n;

    int banned = -1;
    while(remain){
        bool isSelected = false;
        for(int i=0;i<=1000;i++){
            if(i == banned) continue;
            if(cnt[i] && remain - cnt[i+1] - cnt[i] > 0){
                answer.push_back(i);
                banned = i+1;
                cnt[i]--;
                remain--;
                isSelected = true;
                break;
            }
        }

        if(!isSelected){
            for(int i=0;i<=1000;i++){
                while(cnt[i]--) answer.push_back(i);
            }
            remain = 0;
        }
    }

    for(int i:answer){
        cout<<i<<' ';
    }
    return 0;
}