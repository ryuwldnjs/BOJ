#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> r, l, psum_r, psum_l;
vector<int> ans;
int main(){
    cin>>n;
    r = l = psum_r = psum_l = vector<int>(n+1);
    for(int i=0;i<n;i++){
        int x; cin>>x;
        if(x > 0) r[x]++;
        else l[-x]++;
    }
    for(int i=0;i<=n;i++){
        if(i==0) psum_r[i] = r[i];
        else psum_r[i] = psum_r[i-1] + r[i];
    }
    for(int i=n;i>=0;i--){
        if(i==n) psum_l[i] = l[i];
        else psum_l[i] = psum_l[i+1] + l[i];
    }
    for(int i=0;i<=n;i++){
        if(i + psum_l[i] + psum_r[i] == n) ans.push_back(i);
    }
    cout<<ans.size()<<'\n';
    for(auto i : ans){
        cout<<i<<' ';
    }
    return 0;
}