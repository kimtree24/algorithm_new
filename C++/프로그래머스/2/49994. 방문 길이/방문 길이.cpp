#include <string>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

int solution(string dirs) {
    int ans = 0;
    
    map<string, int> m;
    int cr = 0;
    int cc = 0;
    
    map<char, pair<int, int>> dm = {{'U', {1,0}}, 
                                   {'D', {-1,0}}, 
                                   {'R', {0,1}}, 
                                   {'L', {0,-1}}};
    
    for(char c : dirs){
        int nr = dm[c].first + cr;
        int nc = dm[c].second + cc;
        
        // 이동 가부 판단
        if(nr >= -5 && nr <= 5 && nc >= -5 && nc <= 5){
            // 이동했던 좌표인지 확인
            string temp = "";
            vector<pair<int, int>> direction;
            direction.push_back({cr, cc});
            direction.push_back({nr, nc});
            sort(direction.begin(), direction.end());
            for(int i = 0; i < 2; i++){
                temp += to_string(direction[i].first);
                temp += to_string(direction[i].second);
            }
            
            if(m[temp] != 1){
                m[temp] += 1;
                ans += 1;
            }
            
            cr = nr;
            cc = nc;
            
        }
        
    }
    
    return ans;
}