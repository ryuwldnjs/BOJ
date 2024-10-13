#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;
int n,nn, MAX=-1;
map<string, int> m;
string ans;
int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        string a; cin>>a>>nn;
        while(nn--){
            string tag; cin>>tag;
            m[tag]++;
        }
    }

    for(auto it = m.begin(); it!= m.end(); it++){
        if(it->second > MAX){
            MAX = it->second;
            ans = it->first;
        }
        else if(it->second == MAX){
            ans = "-1";
        }
    }
    cout<<ans;
    return 0;
}