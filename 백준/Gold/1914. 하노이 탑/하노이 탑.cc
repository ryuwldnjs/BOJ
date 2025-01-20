#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using pii=pair<int,int>;

class BigInteger {
private:
    string number;

public:
    BigInteger(string num = "0") : number(num) {}

    BigInteger operator*(int x) {
        string result;
        int carry = 0;

        for (int i = number.size() - 1; i >= 0; i--) {
            int prod = (number[i] - '0') * x + carry;
            carry = prod / 10;
            result.push_back((prod % 10) + '0');
        }
        while (carry) {
            result.push_back((carry % 10) + '0');
            carry /= 10;
        }

        reverse(result.begin(), result.end());
        return BigInteger(result);
    }
        // 두 BigInteger를 빼는 함수
    BigInteger operator-(int x) const {
        string result = number;
        int i = result.size() - 1;
        result[i] -= x;  // 끝자리에서 x를 뺌

        // 처리 중 음수가 발생하면 자리 빌림
        while (i > 0 && result[i] < '0') {
            result[i] += 10;
            result[--i] -= 1;
        }

        // 필요 없는 0 제거
        if (result[0] == '0' && result.size() > 1) {
            result.erase(0, result.find_first_not_of('0'));
        }

        return BigInteger(result);
    }

    friend ostream &operator<<(ostream &os, const BigInteger &bigInt) {
        os << bigInt.number;
        return os;
    }
};

int n,cnt;
vector<pii> answer;
void move(int level, int from, int to){
    int via = 6 - from - to; // 1,2,3중에서 from, to 둘다 아닌 나머지 하나
    if(level == 1){
        cnt++;
        if(n<=20) answer.push_back({from, to});
        return;
    }
    move(level-1, from, via); 
    move(1, from, to);
    move(level-1, via, to);
    return;
}
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin>>n;
    if(n>20){
        BigInteger cnt("1");
        for(int i=0;i<n;i++){
            cnt = cnt * 2;
        }
        cnt = cnt - 1;
        cout<<cnt;
        return 0;
    }    


    move(n, 1, 3);

    cout<<cnt<<'\n';
    for(auto x: answer){
        cout<<x.first<< ' '<<x.second<<'\n';
    }
    return 0;
}