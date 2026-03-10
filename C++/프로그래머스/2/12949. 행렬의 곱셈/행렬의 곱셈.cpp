#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2){
    int arr1_rl = arr1.size();
    int arr2_cl = arr2[0].size();
    int arr2_rl = arr2.size();
    vector<vector<int>> ans(arr1_rl, vector<int> (arr2_cl, 0));
    for(int r1 = 0; r1 < arr1_rl; r1++){
        vector<int> rows = arr1[r1];
        for(int c2 = 0; c2 < arr2_cl; c2++){
            vector<int> cols;
            for(int r2 = 0; r2 < arr2_rl; r2++){
                cols.push_back(arr2[r2][c2]);
            }
            int result = 0;
            for(int i = 0; i < cols.size(); i++){
                result += rows[i] * cols[i];
            }
            ans[r1][c2] = result;
        }
    }
    
    return ans;
}