#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int n;
int r1,c1,r2,c2;

char getAlpha(int r, int c){
    int SIZE = n * 2 - 1;
    r %= SIZE; c %= SIZE;

    int diff = abs(n-1 - r) + abs(n-1 - c);
    if(diff >= n) return '.';
    
    diff %= 26;

    return 'a' + diff;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>r1>>c1>>r2>>c2;

    for(int r = r1; r <= r2; r++){
        for(int c = c1; c <= c2; c++){
            cout<<getAlpha(r, c);
        }
        cout<<'\n';
    }
    return 0;
}