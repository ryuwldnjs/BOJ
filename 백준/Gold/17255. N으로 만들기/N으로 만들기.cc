#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
using ll=long long;
string n;
unordered_map<string, ll> dp;

ll solve(string num){
    ll &res = dp[num];
    if(res) return res;

    
    string num_a = num.substr(0, num.size()-1);
    string num_b = num.substr(1);

    if(num_a == num_b) return res = solve(num_a);
    return res = solve(num_a) + solve(num_b);
}

int main(){
    cin>>n;
    for(int i=0;i<=9;i++) dp[to_string(i)] = 1;
    cout<<solve(n);
    return 0;
}