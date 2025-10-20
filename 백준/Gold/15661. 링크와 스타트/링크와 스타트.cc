#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int s[25][25], ability[1<<20];
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>s[i][j];
        }
    }

    //bit조합
    for(int bit=0;bit<(1<<n);bit++){
        for(int i=0;i<n;i++){
            if((bit & (1<<i)) == 0) continue;
            for(int j=i+1;j<n;j++){
                if((bit & (1<<j)) == 0) continue;
                ability[bit] += s[i][j] + s[j][i];                 
            }
        }
    }


    int answer = 1e9;
    for(int bit=1;bit<(1<<n)-1;bit++){
        int start = ability[bit];
        int link = ability[(~bit) & ((1<<n)-1)];
        // printf("%d %d\n", start, link);
        answer = min(answer, abs(start - link));
    }

    cout<<answer;
    return 0;
}