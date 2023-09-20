#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    long long answer = 0;
    long long psum[500000+5]={};
    int n = sequence.size();
    for(int i=0,flag=1;i<sequence.size(); i++, flag *= -1){
        sequence[i] *= flag;
    }
    for(int i=0;i<sequence.size();i++){
        psum[i+1] = psum[i] + sequence[i]; // 인덱스 보정
    }
    sort(psum, psum+n+1);
    answer = psum[n] - psum[0];
    return answer;
}