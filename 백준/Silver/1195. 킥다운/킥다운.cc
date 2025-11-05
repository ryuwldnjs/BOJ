#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

string a,b;

//a의 idx위치에 b를 넣는게 가능한지
bool isAble(int idx){
    for(int i=0;i<b.size();i++){
        if(idx+i >= a.size()) break;
        if(a[idx + i] == b[i] && b[i] == '2') return false;
    }

    return true;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>a>>b;
    
    int answer = a.size() + b.size();
    // cout<<isAble(1)<<'\n';

    for(int i=0;i<a.size();i++){
        int len = max(a.size(), b.size() + i);
        if(isAble(i)) answer = min(answer, len);
    }
    swap(a, b);
    for(int i=0;i<a.size();i++){
        int len = max(a.size(), b.size() + i);
        if(isAble(i)) answer = min(answer, len);
    }

    cout<<answer;
    return 0;
}