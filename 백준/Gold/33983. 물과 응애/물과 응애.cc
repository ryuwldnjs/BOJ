#include <bits/stdc++.h>

using namespace std;

using ll=long long;

using pii=pair<int,int>;

using pll=pair<ll,ll>;

int n;

string str;

void solve(){

    vector<int> prefix(n), suffix(n);

    for(int i=0;i<n;i++){

        if(i>0)prefix[i] = prefix[i-1];

        if(str[i] == 'H') prefix[i]++;

    }

    for(int i=n-1;i>=0;i--){

        if(i<n-1)suffix[i] = suffix[i+1];

        if(str[i] == 'H') suffix[i]++;

    }

    int num=0;

    bool isAnswer = true;

    for(int i=0;i<n;i++){

        if(str[i] != 'O') continue;

        num++;

        if(prefix[i] < num) isAnswer = false;

    }

    num = 0;

    for(int i=n-1;i>=0;i--){

        if(str[i] != 'O') continue;

        num++;

        if(suffix[i] < num) isAnswer = false;

    }

    if(prefix[n-1]*3 != n*2) isAnswer = false;

    

    if(isAnswer) cout<<"pure";

    else cout<<"mix";

}

int main(){

    cin.tie(0) -> sync_with_stdio(0);

    cin>>n>>str;

    solve();

    return 0;

}