#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<int> answer;
int a;
void makeAnswer(int b){
    vector<int> ret;
    ret.push_back(a);
    ret.push_back(b);

    while(true){
        int val = ret[ret.size()-2] - ret[ret.size()-1];
        if(val < 0) break;
        ret.push_back(val);
    }
    if(ret.size() > answer.size()){
        answer = ret;
    }
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>a;

    for(int b=1;b<=a;b++){
        makeAnswer(b);
    }
    cout<<answer.size()<<'\n';
    for(int i: answer) cout<<i<<' ';
    return 0;
}