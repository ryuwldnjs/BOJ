#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;


vector<vector<int>> profit;
vector<int> origin;
//i번째 자리의 해당 알파벳을 Z로 바꿨을때 이득보는 값
//각 자리수별 숫자

bool cmp(vector<int>&a, vector<int>&b){
    for(int i=52;i>=0;i--){
        if(a[i] != b[i]) return a[i] > b[i];
    }
    return false;
}
int main(){
    cin.tie(0) -> sync_with_stdio(0);
    int n;cin>>n;
    origin.resize(55);
    profit.resize(36, vector<int>(55));

    for(int i=0;i<n;i++){
        string num; cin>>num;
        reverse(num.begin(), num.end());
        
        for(int i=0;i<num.size();i++){
            int val;

            if('0'<=num[i]&&num[i]<='9') val = num[i] - '0';
            else val = (num[i] - 'A') + 10; 
            profit[val][i] += 35 - val;
            origin[i] += val;
        }
    }


    for(int i=0;i<36;i++){
        for(int j=0;j<52;j++){
            int carry = profit[i][j] / 36;
            profit[i][j] %= 36;
            profit[i][j+1] += carry;
        }
    }

    sort(profit.begin(), profit.end(), cmp);
    int k;cin>>k;


    //i번째 자리부터
    vector<char> answer;
    int carry = 0;
    for(int i=0;i<52;i++){
        int sum = origin[i] + carry;
        for(int j=0;j<k;j++){
            sum += profit[j][i];
        }
        carry = sum / 36;
        sum %= 36;
        if(sum <= 9) answer.push_back('0' + sum);
        else answer.push_back('A' + sum - 10);
    }
    while(answer.back() == '0') answer.pop_back();
    reverse(answer.begin(), answer.end());

    if(answer.empty()) answer.push_back('0');
    for(char c: answer) cout<<c;
    return 0;
}