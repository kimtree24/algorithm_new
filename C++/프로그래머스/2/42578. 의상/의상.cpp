# include <vector>
# include <map>
# include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes){
    
    map<string, int> m;
    
    int ans = 1;
    
    for(vector<string>clothe: clothes){
        m[clothe[1]] += 1;
    }
    
    for(const auto &p:m){
        ans = (p.second + 1) * ans;
    }
    
    return ans - 1;
    
}