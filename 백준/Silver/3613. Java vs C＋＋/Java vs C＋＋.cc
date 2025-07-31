#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

bool hasUpper;
bool has_;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    string str;cin>>str;

    for(char c: str){
        if(c == '_') has_ = true;
        if('A' <= c && c<= 'Z') hasUpper = true;
        
    }
    for(int i=1;i<str.size();i++){
        if(str[i-1] == str[i] && str[i] == '_'){
            has_ = hasUpper = true;
        }
    }
    if('A' <= str[0] && str[0]<= 'Z') has_ = hasUpper = true;
    if(str.front() == '_' || str.back() == '_') has_ = hasUpper = true;

    if(hasUpper &&has_){
        cout<<"Error!";
        return 0;
    }


    if(hasUpper){
        for(char c: str){
            if('A' <= c && c<= 'Z'){
                cout<<"_"<<(char)(c - 'A' + 'a');
            }
            else cout<<c;
        }
    }
    else if(has_){
        bool isUpper = false;
        for(char c: str){
            if(c == '_'){
                isUpper = true;
                continue;
            }
            if(isUpper) c += 'A' - 'a';
            cout<<(char)c;
            isUpper = false;
        }
    }
    else cout<<str;
    return 0;
}