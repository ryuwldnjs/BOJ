#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
vector<ll> a;
vector<vector<ll> > psum;
ll n,answer;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    a.resize(n);
    psum.resize(n+1, vector<ll>(3));
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=a.size() - 1; i>=0;i--){
        psum[i][0] = psum[i+1][0];
        psum[i][1] = psum[i+1][1];
        psum[i][2] = psum[i+1][2];

        if(a[i] >= 2) psum[i][2]++;
        else psum[i][a[i]]++;
    }

    for(int i=0;i<a.size()-1; i++){
        // printf("%d %d %d \n", psum[i][0],psum[i][2],psum[i][2]);
        if(a[i] == 0) answer += psum[i+1][0] + 2*psum[i+1][1] + psum[i+1][2];
        else if(a[i] == 1) answer += 2*psum[i+1][0];
        else answer += psum[i+1][0];
    }
    cout<<answer;
    return 0;
}