#include <vector>
#include <utility>
#include <deque>

using namespace std;

int solution(vector<vector<int>> maps){
    int rows = maps.size();
    int cols = maps[0].size();
    
    vector<vector<int>> visited(rows, vector<int>(cols, 0));
    
    int dr[4] = {0,0,1,-1};
    int dc[4] = {1,-1,0,0};
    
    deque<pair<pair<int,int>,int>> dq;
    
    dq.push_back({{0,0}, 1});
    visited[0][0] = 1;
    
    while(!dq.empty()){
        auto cur = dq.front();
        dq.pop_front();
        int cr = cur.first.first;
        int cc = cur.first.second;
        
        int dist = cur.second;
        
        if(cr == rows - 1 && cc == cols - 1){
            return dist;
        }
        
        for(int i = 0; i < 4; i++){
            int nr = cr + dr[i];
            int nc = cc + dc[i];
            
            if(nr >= 0 && nr < rows &&
                nc >= 0 && nc < cols &&
                maps[nr][nc] != 0 &&
                visited[nr][nc] != 1){
                visited[nr][nc] = 1;
                dq.push_back({{nr, nc}, dist + 1});
            }
        }
    }
    return -1;
}