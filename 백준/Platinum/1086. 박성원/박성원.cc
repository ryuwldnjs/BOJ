#include <iostream>
#include <vector>
using namespace std;
using ll=long long;
ll n,k;
vector<vector<ll>> dp((1<<15), vector<ll>(101, -1));
//dp[bit][remainder]: bit조합을 시작으로 k로나눈 나머지가 remainder일때의 모든 경우의 수
vector<ll> cache(55);
vector<string> arr; //원본 숫자
vector<ll> nums;//나머지 적용된 숫자

ll factorial(ll n){
    ll res = 1;
    for(ll i=2;i<=n;i++) res *= i;
    return res;
}
ll gcd(ll a, ll b){
    if(b==0) return a;
    return gcd(b, a%b);
}
ll getRemainder(string num){
    ll res = 0;
    for(char ch: num){
        res *= 10;
        res += ch - '0';
        res %= k;
    }
    return res;
}


//bit조합으로 구성된 나머지가 now
ll solve(ll bit, ll now){
    if(bit == (1<<n)-1){
        // printf("%d\n", now);
        if(now%k == 0) return 1;
        return 0;
    }
    // printf("%d\n", now);
    ll &ret = dp[bit][now];
    if(ret != -1) return ret;

    ret = 0;

    for(ll i=0;i<n;i++){
        if(bit & (1<<i)) continue;
        ll next_bit = bit | (1<<i);
        ll next = ((now * cache[arr[i].size()]) % k + nums[i]) % k;
        // getRemainder(to_string(now) + to_string(nums[i]));
        ret += solve(next_bit, next);
    }

    return ret;
}
int main(){
    cin>>n;
    for(ll i=0;i<n;i++){
        string str; cin>>str;
        arr.push_back(str);
    }
    cin>>k;

    cache[0] = 1%k;
    for(int i=1;i<51;i++) cache[i] = (cache[i-1] * 10) % k;
    
    for(ll i=0;i<n;i++){
        nums.push_back(getRemainder(arr[i]));
        // printf("%d ", nums[i]);
    }
    ll cnt = solve(0, 0);
    ll total = factorial(n);
    // cout<<cnt<<' '<<total<<'\n';
    cout<<cnt / gcd(cnt,total) <<'/' << total / gcd(cnt,total);
    return 0;
}