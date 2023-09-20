#include <string>
#include <vector>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> arr(2, k), psum;
    while(k != 1){
        if(k%2 == 0) k/=2;
        else k = 3*k + 1;
        
        // if(arr.size()>=4 && (double) arr[arr.size()-2]/arr.back() == (double) arr.back()/k) 
        //     arr[arr.size()-1] = k;
        // else arr.push_back(k);
        arr.push_back(k);
    }
    psum.resize(arr.size());
    int n = arr.size() -1;
    
    for(int i=1;i<psum.size();i++){
        psum[i] = psum[i-1] + arr[i];
        printf("%d ", arr[i]);
    }
    printf("%d", n);
    
    
    for(int i=0;i<ranges.size();i++){
        int a = ranges[i][0] + 1; // 인덱스 보정
        int b = n + ranges[i][1];
        
        if(a > b){
            answer.push_back(-1.0);
            continue;
        }
        else if(a == b){
            answer.push_back(0.0);
            continue;
        }
        
        double tmp = (double) psum[b] - psum[a-1] - (arr[b]+arr[a])/2.0;
        answer.push_back(tmp);
    }
    return answer;
}