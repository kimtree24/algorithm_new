#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    for(int z = 0; z < t; z++){
        // 입력값으로 초기화
        int m, n, k;
        cin >> m >> n >> k;
        vector<vector<int>> matrix(m, vector<int>(n, 0));
        for(int x = 0; x < k; x++){
            int r, c;
            cin >> r >> c;
            matrix[r][c] = 1;
        }
        int num = 0;
        vector<vector<int>> visited(m, vector<int>(n, 0));
        vector<vector<int>> move = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        // 돌면서 카운트
        for(int r = 0; r < m; r++){
            for(int c = 0; c < n; c++){
                // 첫 방문
                if(matrix[r][c] == 1 && visited[r][c] == 0){
                    // bfs
                    deque<vector<int>> dq;
                    dq.push_back({r,c});
                    visited[r][c] = 1;
                    
                    while(!dq.empty()){
                        vector<int> cur = dq.front();
                        dq.pop_front();
                        for(auto next:move){
                            int n_r = cur[0] + next[0];
                            int n_c = cur[1] + next[1];
                            if(0<= n_r && n_r < m && 0 <= n_c && n_c < n && matrix[n_r][n_c] == 1 && visited[n_r][n_c] == 0){
                                dq.push_back({n_r, n_c});
                                visited[n_r][n_c] = 1;
                            }
                        }
                    }
                    
                    num += 1;
                    
                }
            }
        }
        cout << num << "\n";
    }
    return 0;
}