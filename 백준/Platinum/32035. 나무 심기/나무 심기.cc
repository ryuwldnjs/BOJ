#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
const int SIZE = 200;

vector<vector<char>> answer(4, vector<char>(SIZE, '.'));
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int a,b;cin>>a>>b;
    if(b%2==1){
        cout<<"NO";
        return 0;
    }
    if(b >= 2){
        answer[1][0] = 'O';
        for(int i=1;i<=(b-2)/2;i++){
            answer[1][i] = 'O';
            if(i%2==0) answer[0][i] = 'O';
            if(i%2==1) answer[2][i] = 'O';
        }
        for(int i=1;i<=a;i++){
            answer[1][i + (b-2)/2] = 'O';
        }
        answer[1][a + (b-2)/2 + 1] = 'O';
    }
    else{//b == 0
        if(a == 1){
            answer[0][0] = 'O';
        }
        else if(a == 4){
            answer[0][0] = 'O';
            answer[0][1] = 'O';
            answer[1][0] = 'O';
            answer[1][1] = 'O';
        }
        else if(a == 7){
            answer[0][0] = 'O';
            answer[0][1] = 'O';
            answer[1][0] = 'O';
            answer[1][1] = 'O';
            
            answer[1][2] = 'O';
            answer[2][1] = 'O';
            answer[2][2] = 'O';            
        }

        else if(a >= 8 && a%2==0){
            answer[0][0] = 'O';
            answer[1][0] = 'O';
            answer[2][0] = 'O';
            for(int i=1;i<=(a-6)/2;i++){
                answer[0][i] = 'O';
                answer[2][i] = 'O';
            }
            answer[0][(a-6)/2 + 1] = 'O';
            answer[1][(a-6)/2 + 1] = 'O';
            answer[2][(a-6)/2 + 1] = 'O';
        }
        else if(a >= 11 && a%2==1){
            a -= 3;
            answer[0][0] = 'O';
            answer[1][0] = 'O';
            answer[2][0] = 'O';
            for(int i=1;i<=(a-6)/2;i++){
                answer[0][i] = 'O';
                answer[2][i] = 'O';
            }
            answer[0][(a-6)/2 + 1] = 'O';
            answer[1][(a-6)/2 + 1] = 'O';
            answer[2][(a-6)/2 + 1] = 'O';

            answer[2][(a-6)/2 + 2] = 'O';
            answer[3][(a-6)/2 + 1] = 'O';
            answer[3][(a-6)/2 + 2] = 'O';
        }
        else{
            cout<<"NO";
            return 0;
        }
    }


    cout<<"YES\n"<<4<<' '<<SIZE<<'\n';
    for(int i=0;i<4;i++){
        for(int j=0;j<SIZE;j++){
            cout<<answer[i][j];
        }
        cout<<'\n';
    }
    return 0;
}