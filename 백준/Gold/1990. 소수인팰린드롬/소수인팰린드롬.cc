#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
vector<int> primes;

bool isPrime(int num){
    if(num < 2) return false;

    for(int i=2;i*i<=num;i++){
        if(num % i == 0) return false;
    }
    return true;
}
void preprocess(){
    vector<int> nums;
    for(int i=1;i<=9999;i++){
        string tmp = to_string(i);
        string reversed = tmp; reverse(reversed.begin(), reversed.end());

        string num1 = tmp + reversed;
        string num2 = tmp + reversed.substr(1);

        nums.push_back(stoi(num1));
        nums.push_back(stoi(num2));
    }
    sort(nums. begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());

    for(int num : nums){
        if(isPrime(num)) primes.push_back(num);
    }

}

int main(){
    cin.tie(0) -> sync_with_stdio(0);
    preprocess();
    int a,b; cin>>a>>b;

    for(int prime : primes){
        if(a<=prime&&prime<=b) cout<<prime<<'\n';
    }
    cout<<-1;
    return 0;
}