#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int width, height;
int solution(vector<vector<int>> sizes) {
    for(auto &x:sizes){
        sort(x.begin(), x.end());
        width = max(width, x[0]);
        height = max(height, x[1]);
    }
    return width*height;
}