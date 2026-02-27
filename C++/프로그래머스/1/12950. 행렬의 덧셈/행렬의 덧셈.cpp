# include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1,vector<vector<int>> arr2 ){
    
    int rows = arr1.size();
    int cols = arr1[0].size();
    
    vector<vector<int>> ans(rows, vector<int>(cols));
    
    for (int r = 0; r < rows; r++){
        for (int c = 0; c < cols; c++){
            ans[r][c] = arr1[r][c] + arr2[r][c];
        }
    }
    
    return ans;
}