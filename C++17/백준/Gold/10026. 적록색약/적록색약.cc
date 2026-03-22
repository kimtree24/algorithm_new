#include <vector>
#include <iostream>
#include <deque>
#include <tuple>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    
    vector<string> matrix;

    for(int z = 0; z < n; z++){
        string line;
        cin >> line;
        matrix.push_back(line);
    }
    
    // 이동 좌표
    vector<vector<int>> dirs = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    
    //bfs -> 일반 사람
    int cnt_nomal = 0;
    
    vector<vector<int>> visited(n, vector<int>(n, 0));

    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++ ){
            if(!visited[r][c]){
                cnt_nomal += 1;
                deque<pair<int, int>> dq;
                dq.push_back({r, c});
                visited[r][c] = 1;

                char color = matrix[r][c];

                while(!dq.empty()){
                    auto cur = dq.front();
                    dq.pop_front();

                    for(auto dir:dirs){
                        int nr = cur.first + dir[0];
                        int nc = cur.second + dir[1];

                        if(nr >= 0 && nr < n && nc >= 0 && nc < n && visited[nr][nc] != 1 && matrix[nr][nc] == color){
                            dq.push_back({nr, nc});
                            visited[nr][nc] = 1;
                        }
                    }
                }
            }
        }
    }
    
    cout << cnt_nomal << " ";

    //bfs -> 적록색맹
    int cnt_rg = 0;
    
    vector<vector<int>> visited_rg(n, vector<int>(n, 0));
    visited_rg[0][0] = 1;

    for(int r = 0; r < n; r++){
        for(int c = 0; c < n; c++ ){
            if(!visited_rg[r][c]){
                cnt_rg += 1;
                deque<pair<int, int>> dq;
                dq.push_back({r, c});
                visited_rg[r][c] = 1;

                char color = matrix[r][c];

                while(!dq.empty()){
                    auto cur = dq.front();
                    dq.pop_front();

                    for(auto dir:dirs){
                        int nr = cur.first + dir[0];
                        int nc = cur.second + dir[1];

                        if(nr >= 0 && nr < n && nc >= 0 && nc < n && visited_rg[nr][nc] != 1){
                            if(matrix[nr][nc] == 'R' && color == 'R' || matrix[nr][nc] == 'R' && color == 'G' || matrix[nr][nc] == 'G' && color == 'R' || matrix[nr][nc] == 'G' && color == 'G' ){
                                dq.push_back({nr, nc});
                                visited_rg[nr][nc] = 1;
                            }else if(matrix[nr][nc] == 'B' && color == 'B'){
                                dq.push_back({nr, nc});
                                visited_rg[nr][nc] = 1;                                
                            }

                        }
                    }
                }
            }
        }
    }

    cout << cnt_rg;
    
    return 0;
    
}