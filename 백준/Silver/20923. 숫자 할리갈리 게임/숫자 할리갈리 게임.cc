#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

deque<int> decka, deckb;
deque<int> grounda, groundb;

void turnA(){
    int card = decka.back();
    decka.pop_back();
    grounda.push_front(card);
}
void turnB(){
    int card = deckb.back();
    deckb.pop_back();
    groundb.push_front(card);
}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin>>n>>m;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        decka.push_back(a);
        deckb.push_back(b);
    }

    for(int i=0;i<m;i++){
        if(i%2==0) turnA();
        else turnB();

        if(decka.empty()){
            cout<<"su";
            return 0;
        }
        if(deckb.empty()){
            cout<<"do";
            return 0;
        }
        
        
        //도도 승
        if(grounda.size()&&grounda.front()==5 || groundb.size()&&groundb.front()==5){
            while(!groundb.empty()){
                decka.push_front(groundb.back());
                groundb.pop_back();
            }
            while(!grounda.empty()){
                decka.push_front(grounda.back());
                grounda.pop_back();
            }
        }
        //수연 승
        if(grounda.size() && groundb.size() && grounda.front() + groundb.front() == 5){
            while(!grounda.empty()){
                deckb.push_front(grounda.back());
                grounda.pop_back();
            }
            while(!groundb.empty()){
                deckb.push_front(groundb.back());
                groundb.pop_back();
            }
        }

    }

    if(decka.size() > deckb.size()) cout<<"do";
    else if(decka.size() < deckb.size()) cout<<"su";
    else cout<<"dosu";
    return 0;
}