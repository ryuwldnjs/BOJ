#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

int n;
int a[55];

int decreaseOdd(){
    int ret = 0;
    for(int i=0;i<n;i++){
        if(a[i]%2 == 1){
            ret++;
            a[i]--;
        }
    }
    return ret;
}

int divideAll(){
    int ret = 0;
    for(int i=0;i<n;i++){
        if(a[i]>0) {
            ret = 1;
            a[i]/=2;
        }
    }
    return ret;
}


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];


    int answer = 0;
    for(int i=0;i<=1000;i++){
        answer += decreaseOdd();
        if(divideAll()) answer++;
        else break;
    }

    cout<<answer;
    return 0;
}