#include <vector>
#include <iostream>
#include <deque>

using namespace std;

int main(){
    int t;
    cin >> t;
    for(int tt = 0; tt < t; tt++){
        int len;
        cin >> len;
        vector<vector<int>> visited(len,vector<int>(len,0));
        
        int dr[8] = {1,2,2,1,-1,-2,-2,-1};
        int dc[8] = {-2,-1,1,2,2,1,-1,-2};
        
        vector<int> st(2,0);
        vector<int> tar(2,0);
        
        cin >> st[0] >> st[1];
        cin >> tar[0] >> tar[1];
        
        deque<vector<int>> dq;
        
        // 초기화
        dq.push_back({st[0], st[1], 0});
        visited[st[0]][st[1]] = 1;
        
        while(!dq.empty()){
            vector<int> cur = dq.front();
            dq.pop_front();
            
            int cr = cur[0];
            int cc = cur[1];
            int cnt = cur[2];
            
            // 탈출조건
            if(cr == tar[0] && cc == tar[1]){
                cout << cnt << "\n";
            }
            
            for(int i = 0; i < 8; i++){
                int nr = cr + dr[i];
                int nc = cc + dc[i];
                
                if(nr >= 0 && nr < len && nc >= 0 && nc < len && visited[nr][nc] == 0){
                    dq.push_back({nr, nc, cnt + 1});
                    visited[nr][nc] = 1;
                }
                
            }
            
        }
    }
    return 0;
}