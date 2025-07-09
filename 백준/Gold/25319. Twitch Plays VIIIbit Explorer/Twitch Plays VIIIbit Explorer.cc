#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    int y,x;
};
vector<Info> alpha[26];
vector<char> answer;

void printPath(int y, int x, int yy, int xx){
    while(y < yy) {answer.push_back('D'); y++;}
    while(y > yy) {answer.push_back('U'); y--;}
    while(x < xx) {answer.push_back('R'); x++;}
    while(x > xx) {answer.push_back('L'); x--;}
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m,s_size; cin>>n>>m>>s_size;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c; cin>>c;
            alpha[c - 'a'].push_back({i,j});
        }
    }


    string s;cin>>s;
    vector<char> checkpoint;
    int cnt = 0;
    int check_y=0,check_x=0;
    int py=0, px=0;
    while(true){
        bool isSuccess = true;

        for(char target: s){
            if(alpha[target - 'a'].empty()){
                isSuccess = false;
                break;
            }

            auto [y,x] = alpha[target - 'a'].back();
            alpha[target - 'a'].pop_back();
            
            printPath(py, px, y, x);
            answer.push_back('P'); //아이템 줍기
            py = y; px = x;
        }

        if(!isSuccess){
            answer = checkpoint;
            py = check_y; px = check_x;
            printPath(py, px, n-1, m-1);
            break;
        }
        checkpoint = answer;
        check_y = py; check_x = px;
        cnt++;
    }

    cout<<cnt<<' '<<answer.size()<<'\n';
    for(char c: answer) cout<<c;
    return 0;
}