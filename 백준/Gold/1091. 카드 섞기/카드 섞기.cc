#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n;
int p[50], to[50];

bool able(){
    for(int i=0;i<n;i++){
        if(p[i] != i % 3) return false;
    }
    return true;
}

void shuffle(){
    int tmp[50];
    for(int i=0;i<n;i++){
        tmp[to[i]] = p[i];
    }
    for(int i=0;i<n;i++) p[i] = tmp[i];
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i];
    for(int i=0;i<n;i++){
        cin>>to[i];
    }

    for(int i=0;i<1000000;i++){
        if(able()){
            cout<<i;
            return 0;
        }
        shuffle();
    }

    cout<<-1;

    return 0;
}