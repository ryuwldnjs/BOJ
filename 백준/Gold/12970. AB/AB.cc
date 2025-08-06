#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;


int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,k;cin>>n>>k;
    
    int a = 0;
    bool isAnswer = false;
    for(;a<=n;a++){
        int b = n - a;
        if(a*b >= k){
            isAnswer = true;
            break;
        }
    }
    if(!isAnswer){
        cout<<-1;
        return 0;
    }


    int gap = a*(n-a) - k;
    // a는 a-1번 + gap칸 띄워서 a출력
    //나머진 b
    char answer[55]={};
    for(int i=0;i<a-1;i++) answer[i] = 'A';
    answer[a-1 + gap] = 'A';

    for(int i=0;i<n;i++){
        if(answer[i] == 'A') cout<<'A';
        else cout<<'B';
    }
    return 0;
}