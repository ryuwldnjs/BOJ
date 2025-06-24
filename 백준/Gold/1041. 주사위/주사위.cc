#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const ll INF = (ll)1e17;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    ll n;cin>>n;
    vector<ll> dice(6), cnt(4), val(4, INF);
    ll total = 0;
    for(int i=0;i<6;i++){
        cin>>dice[i];
        total += dice[i];
    }

    
    //보이는 면의 개수에 따른 최솟 합
    for(int i=0;i<6;i++){
        val[1] = min(val[1], dice[i]);
    }

    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            if(i+j == 5) continue;
            val[2] = min(val[2], dice[i] + dice[j]);
        }
    }

    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            for(int k=j+1;k<6;k++){
                set<ll> s={i,j,k, 5-i, 5-j, 5-k};
                if(s.size() < 6) continue;
                val[3] = min(val[3], dice[i] + dice[j] + dice[k]);
            }
        }
    }


    if(n==1){
        cout<<accumulate(dice.begin(),dice.end(),0) - *max_element(dice.begin(), dice.end());
        return 0;
    }


    //사이즈별 면이n개 보일대의 주사위 개수
    cnt[3] = (ll)4;
    cnt[2] = (ll)8*n - 12;
    cnt[1] = (ll)4*(n-2)*(n-1) + (n-2)*(n-2);

    
    ll answer = 0;
    for(int i=1;i<=3;i++){
        // printf("val: %d, cnt: %d\n", val[i], cnt[i]);
        answer += cnt[i] * val[i];
    }
    cout<<answer;
    return 0;
}