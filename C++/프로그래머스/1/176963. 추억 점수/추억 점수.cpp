#include <vector>
#include <map>
#include <string>

using namespace std;

vector<int> solution(vector<string> name,
                     vector<int> yearning,
                     vector<vector<string>> photo)
{
    vector<int> ans;
    
    // map 만들기
    map<string, int> m;
    for(int i = 0; i < name.size(); i++){
        m[name[i]] = yearning[i];
    }
    
    for(const vector<string> &ep:photo){
        int score = 0;
        for(string people:ep){
            score += m[people];
        }
        ans.push_back(score);
    }
    
    return ans;
}