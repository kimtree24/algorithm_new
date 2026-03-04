#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> board, int h, int w) {
    int ans = 0;
    vector<pair<int, int>> move = {{-1,0}, {1,0}, {0,-1}, {0,1}}; // 위, 아래, 좌, 우
    int mr = board.size();
    int mc = board[0].size();
    string target = board[h][w];
    
    for(const auto &m:move){
        int nr = h + m.first;
        int nc = w + m.second;
        if(nr >= 0 && nr < mr && nc >= 0 && nc < mc){
            if(board[nr][nc] == target){
                ans += 1;
            }
        }
    }
    
    return ans;
}