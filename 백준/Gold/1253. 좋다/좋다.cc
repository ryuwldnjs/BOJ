#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Info{
    int val, idx_l, idx_r;

    const bool operator<(Info other) const{
        return val < other.val;
    }
};

int n,answer;
vector<int> arr;
vector<Info> sum;
int main(){
    int n; cin>>n;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        arr.push_back(x);
    }
    for(int i=0;i<arr.size();i++){
        for(int j=i+1;j<arr.size();j++){
            int target = arr[i] + arr[j];
            sum.push_back({target, i,j});
        }
    }
    sort(sum.begin(), sum.end());
    for(int i=0;i<arr.size();i++){
        // int target = arr[i];
        Info target = {arr[i],-1,-1};
        int start = lower_bound(sum.begin(), sum.end(), target) - sum.begin();
        int end = upper_bound(sum.begin(), sum.end(), target) - sum.begin();

        for(int j=start; j<end;j++){
            if(target.val == sum[j].val && i!=sum[j].idx_l && i!=sum[j].idx_r){
                answer++;
                break;
            }
        }
    }
    cout<<answer;
    return 0;
}