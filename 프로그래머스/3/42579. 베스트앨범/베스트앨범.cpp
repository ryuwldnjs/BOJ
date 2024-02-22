#include <bits/stdc++.h>
using namespace std;
struct Music{
    int play;
    int idx;
    
    bool operator< (const Music& b) const{
        if(this->play == b.play)
                return this->idx < b.idx;
        return this->play > b.play;
    }
};
vector<Music> music;
unordered_map<string, vector<Music>> type;
unordered_map<string, int> total;
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for(int i=0;i<genres.size();i++){
        music.push_back({plays[i], i});
        total[genres[i]] += plays[i];
        type[genres[i]].push_back({plays[i], i});
    }
    
    vector<pair<int, string>> order;
    for(auto it = total.begin(); it != total.end(); it++){
        order.push_back({it->second, it->first});
    }
    sort(order.begin(), order.end(), greater<pair<int,string>>());
    sort(music.begin(), music.end());
    
    
    for(auto x : order){
        string now = x.second;
        sort(type[now].begin(), type[now].end());
        for(int i=0;i<type[now].size() && i<2; i++){
            answer.push_back(type[now][i].idx);
        }
    }
    return answer;
}