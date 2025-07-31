#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int INF = 1e9;
int A,B;
int a[3000], b[3000]; //해당 값이 나온 위치
void solve(){
    if(A == B){
        cout<<"2\n";
        return;
    }

    for(int i=1;A>=3000 || a[A] == -1;i++){
        if(A < 3000) a[A] = i;

        int next_A=0;
        while(A){
            next_A += (A % 10)*(A % 10);
            A /= 10;
        }
        A = next_A;
    }


    int answer = INF;
    for(int i=1;B>=3000 || b[B] == -1;i++){
        if(B < 3000){
            b[B] = i;
            if(a[B] != -1){
                answer = min(answer, a[B] + b[B]);
            }
        } 

        int next_B=0;
        while(B){
            next_B += (B % 10)*(B % 10);
            B /= 10;
        }
        B = next_B;
    }

    if(answer == INF) cout<<"0\n";
    else cout<<answer<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);

    while(true){
        fill(a, a+3000, -1);
        fill(b, b+3000, -1);
        cin>>A>>B;
        if(A == 0 && B == 0) break;

        cout<<A<<' '<<B<<' ';
        solve();
    }
    return 0;
}