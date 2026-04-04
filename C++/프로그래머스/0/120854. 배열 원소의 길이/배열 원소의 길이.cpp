#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    
    vector<int> ans;
    
    for(string s : strlist){
        ans.push_back(s.size());
    }
    
    return ans;
    
}