#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int arrow[1000000+5];
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;

    int answer = 0;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        if(arrow[x] == 0){ //새로운 화살 장전
            arrow[x]++;
            answer++;
        }

        arrow[x]--;
        arrow[x-1]++;
    }

    cout<<answer;
    return 0;
}