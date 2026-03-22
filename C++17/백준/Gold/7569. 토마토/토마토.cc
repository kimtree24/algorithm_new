#include <vector>
#include <iostream>
#include <deque>
#include <tuple>
#include <algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int m, n, h;
    cin >> m >> n >> h;
    
    vector<vector<vector<int>>> matrix(h, vector<vector<int>>(n, vector<int>(m, 0)));

    deque<tuple<int, int, int>> dq;
    
    for(int z = 0; z < h; z++){
        for(int r = 0; r < n; r++){
            for(int c = 0; c < m; c++){
                cin >> matrix[z][r][c];
                
                if(matrix[z][r][c] == 1){
                    dq.push_back({z,r,c});
                }
            }
        }
    }
    
    int dz[6] = {0,0,0,0,1,-1};
    int dx[6] = {0,0,1,-1,0,0};
    int dy[6] = {1,-1,0,0,0,0};
    
    while(!dq.empty()){
        auto cur = dq.front();
        dq.pop_front();
        int cz = get<0>(cur);
        int cx = get<1>(cur);
        int cy = get<2>(cur);
        
        for(int i = 0; i < 6; i++){
            int nz = cz + dz[i];
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            
            if(nz >= 0 && nz < h && nx >= 0 && nx < n && ny >= 0 && ny < m && matrix[nz][nx][ny] == 0){
                matrix[nz][nx][ny] = matrix[cz][cx][cy] + 1;
                dq.push_back({nz, nx, ny});
            }
        }
    }
    
    int ans = 0;
    
    for(int z = 0; z < h; z++){
        for(int x = 0; x < n; x++){
            for(int y = 0; y < m; y++){
                if(matrix[z][x][y] == 0){
                    cout << -1;
                    return 0;
                }
                ans = max(ans, matrix[z][x][y]);
            }
        }
    }
    
    cout << ans - 1;

    return 0;
}