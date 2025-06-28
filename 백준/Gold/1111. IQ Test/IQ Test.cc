#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;

void solve(){

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    if(n == 1) cout<<"A";
    else if(n == 2){
        if(arr[0] == arr[1]) cout<<arr[0];
        else cout<<"A";
    }
    else{//n 3이상
        if(arr[0]==arr[1]){
            bool isSame = true;
            for(int i=2;i<n;i++){
                if(arr[i] != arr[0]) isSame = false;
            }
            if(isSame) cout<<arr[0];
            else cout<<"B";
            return 0;
        }
        if((arr[1] - arr[2]) % (arr[0] - arr[1]) != 0){
            cout<<"B";
            return 0;
        }

        int a = (arr[1] - arr[2]) / (arr[0] - arr[1]);
        int b = arr[1] - arr[0] * a;

        bool isAnswer = true;
        for(int i=1;i<n;i++){
            if(arr[i-1] * a + b != arr[i]) isAnswer = false;
        }
        if(isAnswer) cout<<arr[n-1]*a+b;
        else cout<<"B";
    }
    return 0;
}