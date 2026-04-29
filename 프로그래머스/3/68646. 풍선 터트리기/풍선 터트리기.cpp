#include <string>
#include <vector>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int n=a.size();
    vector<int> prefix(n), suffix(n);
    prefix[0] = a[0]; suffix[n-1] = a[n-1];
    
    for(int i=1;i<n;i++) prefix[i] = min(a[i], prefix[i-1]);
    for(int i=n-2;i>=0;i--) suffix[i] = min(a[i], suffix[i+1]);
    
    for(int i=0;i<n;i++){
        if(prefix[i] == a[i] || suffix[i] == a[i]) answer++;
    }
    return answer;
}