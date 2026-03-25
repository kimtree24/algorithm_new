#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles){
    int MOD = 1000000007;
    
    vector<vector<int>> dists(n, vector<int>(m, 0));
    
    for(auto &p:puddles){
        int c = p[0] - 1;
        int r = p[1] - 1;
        
        dists[r][c] = -1;
    }
    
    dists[0][0] = 1;
    
    int dr[2] = {0,1};
    int dc[2] = {1,0};
    
    for(int r = 0; r < n; r++){
        for(int c = 0; c < m; c++){
            if(dists[r][c] == -1){
                dists[r][c] = 0;
                continue;
            }
            
            for(int i = 0; i < 2; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr < n && nc < m && dists[nr][nc] != -1){
                    dists[nr][nc] = (dists[nr][nc] + dists[r][c]) % MOD;
                }
            }
        }
    }
    
    
    return dists[n-1][m-1];
}