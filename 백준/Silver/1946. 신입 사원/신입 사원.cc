#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using pii=pair<int,int>;
int t,n;
int main(){
    cin>>t;
    while(t--){
        vector<pii> arr;
        int MIN = 1e9, answer=0;
        cin>>n;
        for(int i=0;i<n;i++){
            int a,b; cin>>a>>b;
            arr.push_back({a,b});
        }
        sort(arr.begin(), arr.end());

        for(auto x : arr){
            if(x.second < MIN){
                MIN = x.second;
                answer++;
            }
        }
        cout<<answer<<'\n';
    }

    
    return 0;
}