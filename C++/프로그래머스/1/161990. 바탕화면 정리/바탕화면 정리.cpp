#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    int rl = wallpaper.size();
    int cl = wallpaper[0].size();
    
    int minr = 51;
    int minc = 51;
    int maxr = 0;
    int maxc = 0;
    
    for(int r = 0; r < rl; r++){
        for(int c = 0; c < cl; c++){
            if(wallpaper[r][c] == '#'){
                minr = min(minr, r);
                minc = min(minc, c);
                maxr = max(maxr, r);
                maxc = max(maxc, c);
            }
        }
    }
    answer.push_back(minr);
    answer.push_back(minc);
    answer.push_back(maxr + 1);
    answer.push_back(maxc + 1);
    return answer;
}