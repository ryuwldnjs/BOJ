#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
ll fibo[55];
void makeFibo(){
    fibo[0] = fibo[1] = 1;
    for(int i=2; i<=50; i++){
        fibo[i] = fibo[i-1] + fibo[i-2] + 1; //루트 고려
    }
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    makeFibo();
 
    ll n,a,b;cin>>n>>a>>b;

    if(a == b) return 0;


    while(true){
        if(a==1 || b == 1) break;
        else if(a <= fibo[n-2]+1 && b <= fibo[n-2]+1){
            a--;
            b--;
            n -= 2;
        }
        else if(a > fibo[n-2]+1 && b > fibo[n-2]+1){
            a -= fibo[n-2]+1;
            b -= fibo[n-2]+1;
            n--;
        }
        else break;
    }


    string answer;
    //루트1번에서 a까지 거리
    int idx = n;
    while(true){
        if(a==1) break;
        if(a <= fibo[idx-2]+1){
            a--;
            idx -= 2;

            answer.push_back('U');
        }
        else if(a > fibo[idx-2]+1){
            a -= fibo[idx-2]+1;
            idx--;

            answer.push_back('U');
        }
        else break;
    }


    //루트1번에서 b까지 거리
    idx = n;
    while(true){
        if(b==1) break;
        if(b <= fibo[idx-2]+1){
            idx -= 2;
            b--;
            answer.push_back('L');
        }
        else if(b > fibo[idx-2]+1){
            b -= fibo[idx-2]+1;
            idx--;

            answer.push_back('R');
        }
        else break;
    }

    cout<<answer<<endl;

    return 0;
}