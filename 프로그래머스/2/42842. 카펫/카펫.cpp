#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    // 노랑 = xy
    // 갈색 = 2x + 2y + 4
    for(int y = 1;y<=brown - 4; y++){
        if(2*yellow == y*(brown - 2*y - 4)){
            answer[1] = y + 2;
            answer[0] = yellow / y + 2;
            return answer;
        }
    }
    return answer;
}