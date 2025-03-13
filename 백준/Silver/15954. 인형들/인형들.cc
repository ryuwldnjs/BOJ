#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long long n,k;
vector<long double> arr, psum;
//오른쪽 끝을 r
long double getStandVar(long long l, long long r){
    // long long l = r-k+1;
    long double avg =  (psum[r] - psum[l-1]) / (r-l+1);
    long double ret = 0;
    for(long long i=l; i<=r; i++){
        ret += (arr[i] - avg) * (arr[i] - avg);
    }

    return sqrt(ret / (r-l+1));
}
int main(){
    cin.tie(0)->sync_with_stdio(0);

    cin>>n>>k;
    cout.precision(11);
    arr.resize(n+1);
    psum.resize(n+1);
    for(long long i=1;i<=n;i++){
        cin>>arr[i];
        psum[i] = psum[i-1] + arr[i];
        
    }
    long double MIN=1e18L;
    //오른쪽 끝 idx를 i
    for(long long i=1;i<=n;i++){
        // MIN = min(MIN, getStandVar(i));
        for(long long j=i+k-1;j<=n;j++){
            MIN = min(MIN, getStandVar(i, j));
        }
    }
    cout<<MIN;
    return 0;
}