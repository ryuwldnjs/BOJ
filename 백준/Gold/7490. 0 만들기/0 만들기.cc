#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

vector<char> op;
int n;

int getSum(){
    int sum = 1;
    int pre = 1;
    for(int i=0;i<n-1;i++){
        int num = i + 2;
        if(op[i] == '+') {
            sum += num;
            pre = num;
        }
        else if(op[i] == '-') {
            sum -= num;
            pre = -num;
        }
        else{
            sum -= pre;
            sum += pre*10 + num * (pre < 0 ? -1 : 1);
            pre = pre*10 + num * (pre < 0 ? -1 : 1);
        }
    }
    return sum;
}

void print(){
    cout<<"1";
    for(int i=0;i<op.size();i++){
        cout<<op[i]<<i+2;
    }
    cout<<'\n';
}

void recur(int idx){
    if(idx == n){
        if(getSum() == 0) print();
        return;   
    }

    op.push_back(' ');
    recur(idx+1);
    op.pop_back();

    op.push_back('+');
    recur(idx+1);
    op.pop_back();


    op.push_back('-');
    recur(idx+1);
    op.pop_back();



}

void solve(){
    cin>>n;

    recur(1);
    cout<<'\n';
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int t; cin>>t; while(t--) solve();
    return 0;
}