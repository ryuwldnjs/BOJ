#include <iostream>
#include <vector>
using namespace std;

int calc(int a, int b, char op){
    if(op=='+') return a+b;
    if(op=='-') return a-b;
    if(op=='*') return a*b;
    // if(op=='/') return a/b;
    return 0;
}
//idx연산자 처리 중. 연산자 기준
int n;
vector<int> nums;
vector<char> ops;
int solve(vector<bool>& flag, int idx){
    int ret=-1e9;
    if(idx>=flag.size()){
        ret = nums[0];
        for(int i=0;i<flag.size();i++){
            int operandR = nums[i+1];
            if(i+1<flag.size() && flag[i+1] == true){
                operandR = calc(nums[i+1], nums[i+2], ops[i+1]);
                ret = calc(ret, operandR, ops[i]);
                i++;
                continue;
            }
            ret = calc(ret, operandR, ops[i]);
            // printf("%d %c %d\n", ret, ops[i], operandR);

        }

        return ret;
    }

    ret = max(ret, solve(flag, idx+1));
    flag[idx]=true;
    ret = max(ret, solve(flag, idx+2));
    flag[idx]=false; 
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin>>n;
    for(int i=0;i<n;i++){
        char c; cin>>c;
        if(i%2==0) nums.push_back(c-'0');
        else ops.push_back(c);
    }

    vector<bool> flag(ops.size());
    cout<<solve(flag, 0);
    // flag = {false, true};
    // cout<<solve(flag, flag.size());
}