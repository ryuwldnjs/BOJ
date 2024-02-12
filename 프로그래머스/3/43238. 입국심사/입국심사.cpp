#include <string>
#include <vector>

using namespace std;

bool able(long long x, long long n, vector<int> & times){ //x초 안에 n명 심사가 가능한가?
    for(int time : times){
        n -= x / time;
    }
    return n <= 0;
}
long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long l=0;
    long long r = 100000000000000LL;
    for(int i=0;i<200;i++){
        long long mid = (l+r) / 2;
        if(able(mid, n, times)) r = mid;
        else l = mid+1;
    }
    answer = l;
    return answer;
}