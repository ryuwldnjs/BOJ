#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<string> strings;

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int r,c;cin>>r>>c;
    strings.resize(c);

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            char c;cin>>c;
            strings[j].push_back(c);
        }
    }

    for(int i=0;i<c;i++) reverse(strings[i].begin(), strings[i].end());
    sort(strings.begin(), strings.end());

    int count = r;
    for(int i=1;i<c;i++){
        int ret = 0;
        for(int j=0;j<r;j++){
            if(strings[i-1][j] == strings[i][j]) ret++;
            else break;
        }
        count = min(count, r - ret - 1);
    }

    cout<<count;
    return 0;
}