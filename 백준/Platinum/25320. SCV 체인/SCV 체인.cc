#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
struct Info{
    string name;
    string action;
    int block;
};
vector<Info> arr;
set<int> rest;
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n,m;cin>>n>>m;
    arr.resize(m);

    for(int i=1;i<=n*2;i++) rest.insert(i);

    for(int i=0;i<m;i++){
        string a,b;
        int c;
        cin>>a>>b>>c;
        arr[i] = {a,b,c};
        rest.erase(c);
    }
    if(rest.count(1)){ //1번 블록이 아직 안쓰임
        cout<<"NO";
        return 0;
    }

    vector<Info> result;
    bool OneisSame = false;
    for(int i=0;i<m-1;i++){
        result.push_back(arr[i]);

        if(arr[i].name == arr[i+1].name){
            string me = arr[i].name;
            string opposite = (me=="A" ? "B" : "A");


            auto it = rest.lower_bound(arr[i].block);
            if(it == rest.end()){
                cout<<"NO";
                return 0;
            }

            result.push_back({opposite, "CHAIN", *it});
            rest.erase(*it);
        }
    }

    result.push_back(arr.back());


    //A로 끝나면
    if(result.back().name == "A"){
        auto it = rest.lower_bound(arr.back().block);
        if(it == rest.end()){
            cout<<"NO";
            return 0;
        }

        result.push_back({"B", "CHAIN", *it});
        rest.erase(*it);
    }


    // //1뒤에 넣을 숫자 짝이 안맞으면
    // for(int i=0;i<result.size()-1;i++){
    //     if(result[i].block == 1){
    //         if(result[i].name == result[i+1].name && rest.size()%2==0
    //         || result[i].name != result[i+1].name && rest.size()%2 == 1){
    //                 cout<<"NO";
    //                 return 0;
    //             }  
    //     }
    // }




    
    cout<<"YES\n";
    for(int i=0;i<result.size();i++){
        cout<<result[i].name<<' '<<result[i].action<<' '<<result[i].block<<'\n';
        
        //1번블록 뒤에 짝수개만큼 몰아주기.
        if(result[i].block == 1){
            //1뒤에 체인이 있으면, 그 뒤에 해줘야함
            if(i+1 < result.size() && result[i+1].action == "CHAIN"){
                cout<<result[i+1].name<<' '<<result[i+1].action<<' '<<result[i+1].block<<'\n';
                i++;
            }
            string me = result[i].name;
            string opposite = (me=="A" ? "B" : "A");
            int sz = rest.size();
            for(int i=0;i<sz;i++){
                cout<<(i%2==0 ? opposite : me)<<" CHAIN "<< *rest.begin()<<'\n';
                rest.erase(*rest.begin());
            }
            
        }
    }

    return 0;
}