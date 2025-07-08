#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

void solve(){

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    string s;cin>>s;
    for(int x=0;x<10;x++){
        string tmp = s;
        tmp.replace(tmp.find('*'), 1, to_string(x));
        int sum = 0;
        for(int i=0;i<13;i++){
            if(i%2==0) sum += tmp[i] - '0';
            else sum += (tmp[i] - '0') * 3;
        }
        if(sum%10==0) cout<<x;
    }
    return 0;
}