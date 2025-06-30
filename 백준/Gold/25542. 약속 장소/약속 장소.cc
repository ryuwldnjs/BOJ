#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
int n,l;
vector<string> names;
bool getAnswer(string &target){
    for(int i=0;i<n;i++){
        int cnt = 0;
        for(int j=0;j<l;j++){
            if(names[i][j] != target[j]) cnt++;
        }
        if(cnt >= 2) return false;
    }
    return true;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    cin>>n>>l;
    names.resize(n);
    for(int i=0;i<n;i++){
        cin>>names[i];
    }


    for(int i=0;i<l;i++){
        string target = names[0];
        for(char c='A';c<='Z';c++){
            target[i] = c;

            if(getAnswer(target)){
                cout<<target;
                return 0;
            }
        }
    }
    cout<<"CALL FRIEND";
    return 0;
}