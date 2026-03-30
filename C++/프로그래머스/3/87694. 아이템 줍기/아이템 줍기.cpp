#include <string>
#include <vector>
#include <deque>

using namespace std;

int solution(vector<vector<int>> rectangle, int characterX, int characterY, int itemX, int itemY) {
    int answer = 0;
    deque<pair<pair<int,int>, int>> dq;
    
    vector<vector<int>> board(102, vector<int>(102, 0));
    vector<vector<int>> visited(102, vector<int>(102, 0));

    for(auto &rec : rectangle){
        int x1 = rec[0]*2;
        int y1 = rec[1]*2;
        int x2 = rec[2]*2;
        int y2 = rec[3]*2;

        for(int i = x1; i <= x2; i++){
            for(int j = y1; j <= y2; j++){
                board[i][j] = 1;
            }
        }
    }

    for(auto &rec : rectangle){
        int x1 = rec[0]*2;
        int y1 = rec[1]*2;
        int x2 = rec[2]*2;
        int y2 = rec[3]*2;

        for(int i = x1+1; i < x2; i++){
            for(int j = y1+1; j < y2; j++){
                board[i][j] = 0;
            }
        }
    }
    
    int dx[4] = {0,0,-1,1};
    int dy[4] = {1,-1,0,0};
    
    // 시작
    dq.push_back({{characterX * 2, characterY * 2}, 0});
    visited[characterX * 2][characterY * 2] = 1;
    
    while(!dq.empty()){
        auto cur = dq.front();
        dq.pop_front();
        int cur_x = cur.first.first;
        int cur_y = cur.first.second;
        int cur_cnt = cur.second;
        
        // 탈출조건
        if(cur_x == itemX * 2 && cur_y == itemY * 2){
            return cur_cnt / 2;
        }
        
        for(int i = 0; i < 4; i++){
            int nr = cur_x + dx[i];
            int nc = cur_y + dy[i];
            
            if(nr >= 0 && nr < 102 && nc >= 0 && nc < 102 && board[nr][nc] == 1 && visited[nr][nc] == 0){
                dq.push_back({{nr, nc}, cur_cnt + 1});
                visited[nr][nc] = 1;
            }
        }
    }
    
    return -1;
}