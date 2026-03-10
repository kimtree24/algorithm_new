#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle){
    int ans;
    vector<vector<int>> new_triangle = triangle;
    
    // 줄 별로 돌기
    for(int r = 0; r < triangle.size(); r++){
        vector<int> row = triangle[r];
        for(int c = 0; c < row.size(); c++){
            // 범위 유효 확인
            if(r+1 < triangle.size()){
                new_triangle[r+1][c] = max(new_triangle[r][c]+triangle[r+1][c], new_triangle[r+1][c]);
                new_triangle[r+1][c+1] = max(new_triangle[r][c] + triangle[r+1][c+1], new_triangle[r+1][c+1]);
            }
            
        }
    }
    
    // for(int i = 0; i < new_triangle.size(); i++){
    //     for(int j = 0; j < new_triangle[i].size(); j++){
    //         cout << new_triangle[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    
    vector<int> last_line = new_triangle[new_triangle.size() - 1];
    
    ans = *max_element(last_line.begin(), last_line.end());
    
    return ans;
}