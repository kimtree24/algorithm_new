#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, pair<vector<pair<int, int>>, int>> m;
    
    for(int i = 0; i < genres.size(); i++){
        m[genres[i]].second += plays[i];
        m[genres[i]].first.push_back({i, plays[i]});
    }
    
    vector<pair<string, pair<vector<pair<int, int>>, int>>> v(m.begin(), m.end());
    
    sort(v.begin(), v.end(), [](auto &a, auto &b){
        return a.second.second > b.second.second;
    });
    
    for(auto &p:v){
        auto &songs = p.second.first;
        sort(songs.begin(), songs.end(), [](auto &a, auto &b){
            if(a.second == b.second){
                return a.first < b.first;
            }
            return a.second > b.second ;
        });
        
        answer.push_back(songs[0].first);
        if(songs.size() > 1){
            answer.push_back(songs[1].first);
        }
    }
    
    return answer;
}